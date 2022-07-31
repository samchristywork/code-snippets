from http.server import BaseHTTPRequestHandler, HTTPServer

class S(BaseHTTPRequestHandler):
  def do_GET(self):
    self.send_response(200)
    self.send_header('Content-type', 'text/html')
    self.end_headers()
    self.wfile.write('<form action="fileupload" method="post" enctype="multipart/form-data">'
                     ' <input type="file" name="file"><br>'
                     ' <input type="submit">'
                     '</form>'.encode('utf-8'))

  def do_POST(self):
    self.send_response(200)
    self.send_header('Content-type', 'text/html')
    self.end_headers()
    length = int(self.headers['Content-Length'])
    data = self.rfile.read(length)
    self.wfile.write("POST request for {}".format(self.path).encode('utf-8'))
    with open('output', 'wb') as f:
      f.write(data)

HTTPServer(('', 8080), S).serve_forever()
