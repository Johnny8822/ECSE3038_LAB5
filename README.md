/////////////////////////////////////////////////////////////////
setup(): This function is called once when the Arduino is powered on or reset. It is used to initialize variables, pin modes, libraries, etc.

loop(): This function contains the main code that runs repeatedly after the setup() function has completed execution. It continuously executes the code inside it in a loop.

LiquidCrystal My_LCD(22,23,5,18,19,21);: This line initializes an instance of the LiquidCrystal class named My_LCD. The numbers passed as arguments are the pin numbers to which the LCD's control pins (RS, EN, D4, D5, D6, D7) are connected.

My_LCD.begin(16, 2);: This line initializes the LCD display with 16 columns and 2 rows.

Serial.begin(9600);: This line initializes the serial communication at a baud rate of 9600 bits per second. This is used for communicating with the computer for debugging purposes.

WiFi.begin(ssid, password);: This line attempts to connect to a WiFi network using the provided SSID (network name) and password.

while(WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }: This loop waits until the WiFi connection is established. It prints dots to the serial monitor to indicate that it's attempting to connect.

Serial.println(WiFi.localIP());: This line prints the local IP address of the Arduino once it's connected to the WiFi network.

HTTPClient http;: This line creates an instance of the HTTPClient class, which allows the Arduino to make HTTP requests.

http.begin(endpoint.c_str());: This line initializes an HTTP connection to the specified endpoint (URL). The c_str() function converts the String object endpoint into a C-style string, which is required by the begin() function.

http.GET();: This line sends an HTTP GET request to the server specified by the endpoint.

http.addHeader("api-key", api_key);: This line adds a custom HTTP header named "api-key" with the value of the api_key variable to the HTTP request.

int httpResponseCode = http.GET();: This line sends another HTTP GET request and stores the HTTP response code returned by the server in the variable httpResponseCode.

if (httpResponseCode>0) { ... }: This conditional block checks if the HTTP response code is greater than zero, indicating a successful response.

String responseBody = http.getString();: This line retrieves the response body (the content of the HTTP response) and stores it in the responseBody variable.

JsonDocument doc;: This line creates a JsonDocument object named doc, which will be used to parse the JSON response from the server.

DeserializationError error = deserializeJson(doc, responseBody);: This line attempts to deserialize (parse) the JSON response into the doc object. Any parsing errors will be stored in the error variable.

String line_1 = doc["line_1"];: This line extracts the value associated with the key "line_1" from the JSON response and stores it in the line_1 variable.

String line_2 = doc["line_2"];: This line extracts the value associated with the key "line_2" from the JSON response and stores it in the line_2 variable.

My_LCD.clear();: This line clears the contents of the LCD display.

My_LCD.setCursor(0,0);: This line sets the cursor position to the first column of the first row on the LCD display.

My_LCD.print(line_1);: This line prints the value stored in the line_1 variable on the LCD display.

My_LCD.setCursor(0,1);: This line sets the cursor position to the first column of the second row on the LCD display.

My_LCD.print(line_2);: This line prints the value stored in the line_2 variable on the LCD display. 




//////////////////////////////////////////////////////////////////////////////////////
Reason for Code : We're at Lab 5, I know the reason, you know the reason....To get a grade 


///////////////////////////////////////////////////////////////////////////////////////// 
Joke: What do you call a Black Woman with multiple abortions? Ans: A crime fighter. 
