from flask import Flask, request, jsonify, render_template

app = Flask(__name__)

submitted_data = "Initial data"

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/data', methods=['GET', 'POST'])
def data():
    global submitted_data
    if request.method == 'POST':
        json_data = request.json
        submitted_data = json_data.get('text', submitted_data)
        return jsonify({"text": submitted_data})
    else:
        return jsonify({"text": submitted_data})

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=1234)
