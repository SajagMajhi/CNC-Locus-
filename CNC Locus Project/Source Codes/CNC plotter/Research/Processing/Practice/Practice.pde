import processing.serial.*;
import javax.swing.JOptionPane;

Serial myPort;
String str;
String portname = null;
boolean streaming = false;
String[] data;

int i=0;

void setup()
{
}

void draw()
{
}

void keyPressed()
{
   if(key == '1') 
    myPort.write('1');
   else if(key == '0')
    myPort.write('0');
   else if(key == 'p')
    selectSerialPort();
   else if(!streaming && key == 'g')
   {
     File file = null;
     data = null;
     selectInput("Select a file to process:", "fileSelected", file);
   }
}

void fileSelected(File obj)
{
  if(obj == null)
   println("No file selected or canceled");
  else 
  {
    println("User selected " + obj.getAbsolutePath());
    data = loadStrings(obj.getAbsolutePath());
 
    streaming = true;
    stream();
  }
}

void stream()
{
  if(!streaming) return;
  
  while(true)
  {
    if(i == data.length)
    {
      streaming = false;
      return;
    }
    
    if (data[i].trim().length() == 0) i++;
    else break;
  }
  
 
  for(i=0;i<data.length;i++)
  {
    // println(data[i]);
     myPort.write(data[i]+'\n');
     delay(1000);
  }
  
}

void selectSerialPort()
{
   String result = (String) JOptionPane.showInputDialog(null,
    "Select the serial port that corresponds to your Arduino board.",
    "Select serial port",
    JOptionPane.PLAIN_MESSAGE,
    null,
    Serial.list(),
    0);
    
    if(result !=null )
    {
      portname = result;
      println(portname);
      openSerialPort();
    }
}

void openSerialPort()
{
  if(portname == null) return;
  else
  { 
   myPort = new Serial(this, portname, 9600);
   myPort.bufferUntil('\n');
  }
}

void serialEvent(Serial port)
{
  str = port.readStringUntil('\n');
  print(str);
}
