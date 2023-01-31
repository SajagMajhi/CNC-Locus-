
char c;

struct point
{
  float x,y,z;
};

void setup()
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() 
{
  delay(100);
  char line[512];
  int lineindex =0;
  bool lineiscomment;
  lineiscomment = false;
  
while(1)
{
  if(Serial.available()>0)
  {
    c=Serial.read();
    if (( c == '\n')) 
    {
      if(lineindex > 0)
      {
         line[lineindex] = '\0'; 
        // Serial.println(line);
         processthisline(line,lineindex);
         lineindex = 0;
      }
    }
    else
    {
      if(lineiscomment)
      {
         if(c == ')')
         {
          lineiscomment=false;      
         }
      }
      else
      {
        if(c== '(')
        {
         lineiscomment=true;
        }
    
        else if ( c >= 'a' && c <= 'z' ) 
        {
          line[lineindex++] = c - 32;
        }
        
        else 
        {
           line[lineindex++] = c;
        }
     }
    }
  
    /*
    if(x == '1')
    {
     digitalWrite(13,HIGH); 
     Serial.println("ON");
    }
    else if( x == '0')
    {
     digitalWrite(13,LOW);
     Serial.println("OFF");
    }  */
  }
 }
}

void processthisline(char *line,int size)
{
   char buffer[64];
   int currentindex = 0;
   struct point newpos;
   while(currentindex < size)
   {
    switch(line[currentindex++])
    {
      case  'G': buffer[0] = line[currentindex];
                 buffer[1] = '\0';
                 
          switch(atoi(buffer))
          {
            case 1: char* indexX = strchr( line , 'X' ); 
                    char* indexY = strchr( line , 'Y' ); 
                    //Serial.println(indexX);

                    newpos.x = atof(indexX+1);
                    newpos.y = atof(indexY+1);
                                        
                    drawthisline(newpos.x,newpos.y);
                    /*
                    if ( indexX <= 0 ) {
                      //newPos.x = atof( indexX + 1);
                      Serial.println("True");
                    }*/                    
          }
      case 'M': buffer[0]=line[currentindex++]; //line[1]
                buffer[1]=line[currentindex++]; //line[2]
                buffer[2]=line[currentindex++]; //line[3]
                buffer[3]='\0';    

                switch(atoi(buffer))
                {
                    case 300: char *indexS = strchr(line,'S'); 
                              Serial.println(indexS);
                              float Spos = atof(indexS+1);

                              if(Spos == 30)
                              {
                                Serial.println("Pen Down");
                              }
                              else if(Spos == 50)
                              {
                                Serial.println("Pen UP");
                              }
                }                                
    }
     // Serial.println(line[currentindex++]);
   }  
}

void drawthisline(float x,float y)
{
     Serial.print(x);
     Serial.print(" ");
     Serial.println(y);
}

