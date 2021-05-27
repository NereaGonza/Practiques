/*
ESP32 Web Server - STA Mode
modified on 25 MAy 2019
by Mohammadreza Akbari @ Electropeak
https://electropeak.com/learn
*/
#include <WiFi.h>
#include <WebServer.h>

// SSID & Password
const char* ssid = "Livebox6-5635";  // Enter your SSID here
const char* password = "oD7t9oaPvJxz";  //Enter your Password here
WebServer server(80);  // Object of WebServer(HTTP port, 80 is defult)
// HTML & CSS contents which display on web server 
String HTML = "<!DOCTYPE html>\
<html>\
<body>\
    <h1>Como afecta la musica a nuestras emociones</h1>\
    <hr color='black' size=3>\
        <h3>8 beneficios que aporta escuchar musica</h3>\
            <p>1. Ayuda a expresar sentimientos</p>\
            <p>2. Modifica nuestro estado de animo</p>\
            <p>3. Favorece la conexion con nuestras emociones</p>\
            <p>4. Mejora el aprendizaje</p>\
            <p>5. Alivia la ansiedad</p>\
            <p>6. Reduce el estres</p>\
            <p>7. Nos permite recordar momentos</p>\
            <p>8. Estimula la creatividad</p>\
    <p> </p>\
    <p> </p>\
    <em>Segun Darwin, en 'El origen de las especies':</em>\
    <p> </p>\
    <em>Los sonidos musicales han sentado una de las bases mas importantes</em>\
    <em>para el desarrollo del lenguaje,</em>\
    <em>ya que tanto el ritmo como la cadencia</em>\
    <em>de la oratoria poseen rasgos musicales.</em>\
    </p>\
    <strong>En conclusion, la musica nos ayuda a liberar tensiones, emocionarnos,</strong>\
    <strong>relajarnos y evocar recuerdos.</strong>\
    <p> </p>\
    <p>Estos serian unos ejemplos de canciones para que usted compruebe los beneficios:</p>\
<ul>\
  <li>Walking on Sunshine, Katrina and The Waves</li>\
  <li>I Will Survive, Gloria Gaynor</li>\
  <li>Living On A Prayer, Bon Jovi</li>\
  <li>Girls Just Wanna Have Fun, Cyndi Lauper</li>\
</ul>\
</body>\
</html>";


// Handle root url (/)
void handle_root() {
server.send(200, "text/html", HTML);
}
void setup() {
Serial.begin(115200);
Serial.println("Try Connecting to ");
Serial.println(ssid);
// Connect to your wi-fi modem
WiFi.begin(ssid, password);
// Check wi-fi is connected to wi-fi network
while (WiFi.status() != WL_CONNECTED) {
delay(1000);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected successfully");
Serial.print("Got IP: ");
Serial.println(WiFi.localIP());  //Show ESP32 IP on serial
server.on("/", handle_root);
server.begin();
Serial.println("HTTP server started");
delay(100);
}
void loop() {
server.handleClient();
}
