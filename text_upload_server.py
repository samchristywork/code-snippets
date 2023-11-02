from flask import Flask, render_template, request
import time

app = Flask(__name__)

def appendToFile(text, file):
    with open(file, 'a') as f:
        f.write(text + '\n')

form = '''
<form method="post">
    <textarea name="text_area" rows="10" cols="50"></textarea><br>
    <input type="submit" value="Submit">
</form>
'''

@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        text = request.form.get('text_area')
        date = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
        appendToFile("Submitted at " + date, "text_upload.txt")
        appendToFile(text, "text_upload.txt")
        return 'Text received.<br><br>' + form
    return form

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')
