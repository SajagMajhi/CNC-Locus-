import processing.serial.*; //Header file declaration
import javax.swing.JOptionPane;

Serial myPort; //class_name object;
String str;

String portname = null;
boolean streaming = false;

String[] gcode;
int i=0;

void openSerialPort()
{
  if(portname == null) return;
  if(myPort != null) myPort.stop();
  
  myPort = new Serial(this, portname, 9600);
  myPort.bufferUntil('\n');
}

void selectSerialPort()
{
  String result = (String) JOptionPane.showInputDialog(frame,
    "Select the serial port that corresponds to your Arduino board.",
    "Select serial port",
    JOptionPane.PLAIN_MESSAGE,
    null,
    Serial.list(),
    0);
    
   if(result != null)
   {
     portname = result;
     openSerialPort();
   }
}

void setup()
{
  size(500, 250);
  openSerialPort(); 
}

void draw()
{
  printArray(str);
}


void keyPressed()
{
   if(key=='1') myPort.write('1');
   else if(key=='2') myPort.write('2');
   else if(key=='p')  selectSerialPort();
   
   else if(!streaming && key=='g')
   {
     File file = null;
     gcode = null;
     selectInput("Select a file to process:", "fileSelected", file);
    /*selectInput("Prompt","Func_name",File obj)
      Prompt = message to be displayed to the user
      Func_name = function to be called after file is selected
     */
   }
}

void fileSelected(File selection) 
{
  if(selection == null)
     println("No file selected or canceled");
   else
   {
     println("User selected " + selection.getAbsolutePath());
     /* selection.getAbsolutePath() gives the file path location
        in string format */
     gcode = loadStrings(selection.getAbsolutePath());
     
     /* the contents of file at the given file path by selection.getAbsolutePath()
        is stored in 2D array gcode*/     
    
    /*printing the entire contents of file at console 
      for (i = 0 ; i < gcode.length; i++) {
        println(gcode[i]);
     } */
     
     if(gcode == null) return;
      streaming = true;
      stream();
   }
}

void stream()
{
   if(!streaming) return;
   
   while(true){
     if(i == gcode.length)
     {
       streaming = false;
       return;
     }
     
     if(gcode[i].trim().length() == 0)
     i++;
     else 
     break; 
   }
     println(gcode[i]);
     port.write(gcode[i] + '\n');
     i++;
}

void serialEvent(Serial port)
{
   str = port.readStringUntil('\n');
   println(str.trim());
   
   if (str.trim().startsWith("ok")) stream();
  if (str.trim().startsWith("error")) stream(); // XXX: really?
}
