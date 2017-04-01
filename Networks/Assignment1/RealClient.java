import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;
import java.io.DataInputStream;
import java.io.InputStream;
import java.io.FileOutputStream;
import java.util.ArrayList;
import java.io.File;




public class RealClient {

    // static String NAME  = "localhost";

    public static void main(String[] args) 
    {

    String NAME = args[0];
       //  int PORT = Integer.parseInt(args[1]);

    String ar = args[1];
    int PORT = Integer.parseInt(ar);

    Scanner consoleReader = new Scanner(System.in);
    System.out.println("Connecting to Server");
    try {
            Socket clientsocket = new Socket(NAME, PORT);
            System.out.println("Connection Made with the Server.");

            // After Connection Setup
            PrintWriter networkOut = new PrintWriter(clientsocket.getOutputStream(), true);
            BufferedReader networkIn = new BufferedReader(new InputStreamReader(clientsocket.getInputStream()));
            System.out.println("Ready to read and write on the network.");

                
            // Starting Echo Loop
            String message = "";
            String mess="";
            String word="";
            System.out.println("Please enter your query: ");
            word = consoleReader.next();
            networkOut.println(word);
            while(!word.equals("quit!")) 
            {
               // networkOut.println(message); 
                ArrayList<String> files = new ArrayList<String>(); 
               
                
             //   networkOut.println(message);
                message = networkIn.readLine();
                int child = Integer.parseInt(message);
                if(child!=0)
                {
                    for(int i=0;i<child;i++)
                    {
                        message = networkIn.readLine();
                        files.add(message);
                        if(message.contains(".txt") || message.contains(".WMV"))
                        {
                            System.out.println("\033[32m " + message);
                        }
                        else
                        {         
                             System.out.println("\033[33m " + message); 
                        }
                    }
                    System.out.println("Press 1 to search another query");
                    System.out.println("Press 2 to download a file from the query");
                    int c = consoleReader.nextInt();
                    String cd = Integer.toString(c);
                    networkOut.println(cd);

                    if(c==2)
                    {
                      //  String cc = Integer.toString(c);
                      //  networkOut.println(cc);
                        System.out.println("Enter the filename: ");
                        String m = consoleReader.next();
                        for(int i=0;i<files.size();i++)
                        {
                            if(files.get(i).endsWith(m))
                            {
                                networkOut.println(m);
                                File file1=null;

                                String mm = files.get(i);
                                System.out.println(mm);
                                boolean bool = false;
                                File f = null;
                                if(files.get(i).endsWith(".WMV"))
                                {
                                     f = new File("./test.WMV");
                                     bool = f.createNewFile();
                                    // file1 = File.createTempFile(mm,".mp4", new File("."));
                                }
                                
                                else if(files.get(i).endsWith(".txt"))
                                {
                                     f = new File("./test1.txt");
                                     bool = f.createNewFile();
                                    // file1 = File.createTempFile(mm,".txt", new File("."));
                                }
                                System.out.println(bool);
                               // mm = file1.getName(); 
                               // System.out.println(mm);
                                FileOutputStream stream = new FileOutputStream(f); 
                                System.out.println(" The file you downloaded has been named test : ");
                                InputStream in = clientsocket.getInputStream(); 
                                DataInputStream dis = new DataInputStream(in);
                                child =  dis.readInt();
                                byte []bytes = new byte[child]; 

                                dis.read(bytes);
                                stream.write(bytes);
                                //System.out.println(file1.length());
                                
                                   
                                break;
                            }
                            if(i==files.size())
                            {
                                System.out.println("Invalid filename.");
                            }
                        }
                    }
                }
                else
                {
                    System.out.println("No files with that name or contain that name");
                }
                System.out.println("Please enter your query: ");
                word = consoleReader.next();
                networkOut.println(word);
            }
            System.out.println("Quitting!"); 
        }
        catch (IOException e) 
        {
            e.printStackTrace();
        }
    }
}