import http.client
import json
import datetime

'''
Author : Tarun Pritam R
Input Constraints:
    Request Type : ['GET', 'POST', 'PUT', 'DELETE']
    File Name : Any file in Server/Client side which operation is to be done    
Output Format:
    Status : <Response_code> Reason : <Response_message> - Request Types ['GET', 'DELETE']
    <JSON_success_failure_response> - Request Types ['PUT', 'POST']
'''

def clientHTTP(conn, request_method, file_name, headers):
    if request_method.upper() == 'GET' or request_method.upper() == 'DELETE':
        conn.request(request_method.upper(), f'/{file_name}',headers=headers)
        response = conn.getresponse()
        res_headers = response.getheaders()
        print(f'Status : {response.status}\n Reason : {response.reason}\n Headers : {res_headers}\n {response.read().decode()}')

    elif request_method.upper() == 'POST' or request_method.upper() == 'PUT':
        #POST and PUT Requests can either upload the file from local directory or Client's input content
        req_type = input('-u --Upload to upload from current directory\n Default - Type file contents\n')
        if req_type == '-u' or req_type == '--Upload':
            try:
                with open(file_name,'r') as file:
                    content = file.read()
            except Exception as err:
                print('Failed to open file',err)
                return 
        else:
            content = input('Type the content : ')
        
        req_body = json.dumps({"content" : content})
        conn.request(request_method.upper(), f'{file_name}', req_body, headers)
        response = conn.getresponse()
        res_headers = response.getheaders()
        print(f'Headers : {res_headers}')
        print(f'Response Body : {response.read().decode()}')
    
    else:
        print('Bad Client Request!')

if __name__ == '__main__':
    #Create a http client connection on PORT 5000 where flask server is launched
    connection = http.client.HTTPConnection('localhost',5000)

    request = input('Request Method : ').strip()
    file_name = input('File name to operate : ').strip()
    headers = {'Content-Type': 'application/json',
                'Host': 'localhost:5000',
               'Accept': 'application/json, text/html',
               'If-Modified-Since': datetime.datetime.now(datetime.timezone.utc).strftime("%Y-%m-%dT%H:%M:%S.%f%Z")}

    clientHTTP(connection, request,file_name,headers)
