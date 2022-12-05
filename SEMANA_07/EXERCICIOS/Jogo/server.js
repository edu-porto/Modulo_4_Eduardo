const path = require('path');
const express = require('express');
const app = express();



app.use(express.static(__dirname  ));

app.get('/', function(req, res) {
    res.sendFile(path.join(__dirname + '/index.html'));
});


app.listen(3333);

console.log('Now the server is running in url: http://127.0.0.1:3333');


// Setting path for public directory 
const static_path = path.join(__dirname, "public");
app.use(express.static(static_path));
app.use(express.urlencoded({ extended: true }));
  

app.post("/lost", (req, res) => {
    res.json([{
       name_recieved: req.body.name
    }])
 })

 app.post("/win", (req, res) => {
    res.json([{
       name_recieved: req.body.name
    }])
 })