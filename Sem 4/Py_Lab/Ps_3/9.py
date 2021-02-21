import sys
import re
import datetime

def validateFile(filename):
    pattern = re.compile('.+\.txt$')
    # result = re.search(pattern,filename)
    result = pattern.match(filename)
    if result:
        return True
    return False

def parseData(logData):
    pattern = '([0-9]{4}-[0-9]{2}-[0-9]{2}T[0-2][1-9]:[0-6][1-9]:[0-6][0-9]).+ ([A-Za-z]+): Device State: ([A-Z]+)'
    data = re.match(pattern,logData)
    deviceName = data.group(2)
    deviceState = data.group(3)
    timestamp = datetime.datetime.strptime(data.group(1), '%Y-%m-%dT%H:%M:%S')

    if deviceState == 'ERR':
        return None,timestamp.timestamp(),None,deviceName,deviceState
    elif deviceState == 'ON':
        # timeDifference = datetime.datetime.now().timestamp() - timestamp.timestamp()
        return timestamp.timestamp(), None, None, deviceName, deviceState
    elif deviceState == 'OFF':
        return None,None,timestamp.timestamp(),deviceName,deviceState

def parseLogFile(filename):
    onDetails = {}
    errDetails = {}
    with open(filename,'r') as f:
        for line in f:
            timeDifference, errTimestamp, downtime, deviceName, deviceState = parseData(line)
            print(timeDifference,errTimestamp,deviceName,deviceState)
            if deviceState == 'ON':
                if deviceName in onDetails.keys():
                    onDetails[deviceName] += int(timeDifference)
                else:
                    onDetails[deviceName] = int(timeDifference)
            elif deviceState == 'OFF':
                if deviceName in onDetails.keys():
                    onDetails[deviceName] -= downtime
            elif deviceState == 'ERR':
                errDetails[deviceName] = errTimestamp 
    return onDetails,errDetails

if __name__ == '__main__':
    if len(sys.argv) == 2:
        if validateFile(sys.argv[1]):
            uptime,errDetails = parseLogFile(sys.argv[1])

        else:
            print('Invalid file : txt files are only allowed')
    else:
        print('Invalid number of arguments')
