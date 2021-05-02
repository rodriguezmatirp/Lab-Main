from flask import Flask, request, render_template
import os,json
import datetime

app = Flask(__name__)
current_dir = os.getcwd()
templates_dir = os.path.join(current_dir,'templates/')

@app.route('/')
def index():
    return "Hello, append filename in routes for perform - GET,POST,PUT,DELETE"

@app.before_request
def log_headers():
    print(f'\nHeaders : \n{request.headers}')

@app.route('/<file_name>',methods = ['POST','GET', 'PUT','DELETE'])
def http_server(file_name):
    
    file_path = templates_dir + file_name
    
    if request.method == 'GET':
        if os.path.isfile(file_path):
            if request.headers.get('If-Modified-Since'):
                date = datetime.datetime.strptime(request.headers["If-Modified-Since"], "%Y-%m-%dT%H:%M:%S.%f%Z")
                check_timestamp = datetime.datetime.timestamp(date)
                last_modified = os.path.getmtime(file_path)
                
                if int(check_timestamp) > int(last_modified):
                    return f'Not Modified Since, {request.headers["If-Modified-Since"]}', 304
            return render_template(file_name),200
        else:
            return render_template('404.html'),404

    elif request.method == 'POST':
        content =request.get_json()["content"]
        try:
            with open(file_path, 'a') as file:
                file.write(content)
            return {"status" : f"File saved in {templates_dir}"},200
        except Exception as err:
            return {"status" : "Failed saving","Error" : err},404

    elif request.method == 'PUT':
        content = request.get_json()["content"]
        try:
            with open(file_path, 'w') as file:
                file.write('\n' + content)
            return {"status" : f"File updated and saved in {templates_dir}!"},200
        except Exception as err:
            return {"status" :"Failed to update", "Error" : err},404
    
    elif request.method == "DELETE":
        if os.path.isfile(file_path):
            os.remove(file_path)
            return {"status" : "File deleted successfully"},200
        else: 
            return render_template('404.html') ,404

@app.after_request
def set_headers(response):
    response.headers['Server'] = 'rodriguez/1.0'
    response.headers['Connection'] = 'Closed'
    return response

@app.route('/check', methods=['POST'])
def check():
    data = request.json
    return f"Test success, {data.get('content')}"

if __name__ == '__main__':
    app.run(debug=True)
