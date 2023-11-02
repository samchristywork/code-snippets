from flask import Flask, render_template, request

app = Flask(__name__)

def appendToFile(text, file):
    with open(file, 'a') as f:
        f.write(text + '\n')

@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        text = request.form.get('text_area')
        appendToFile(text, "text_upload.txt")
        return 'Text received.'
    return '''
    <form method="post">
        <textarea name="text_area" rows="10" cols="50"></textarea><br>
        <input type="submit" value="Submit">
    </form>
    '''

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')
