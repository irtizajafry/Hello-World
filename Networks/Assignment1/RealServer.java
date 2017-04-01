import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.FileWriter;
import java.net.Socket;
import java.util.Scanner;
import java.net.*;
import java.util.*;
import java.io.*;
import java.net.ServerSocket;
import java.util.ArrayList;
import java.io.DataInputStream;
import java.io.InputStream;
import java.lang.*;
 
public class RealServer {
   ServerSocket serversocket;
   boolean On = true;
   public RealServer() 
   { 
      try 
      {
         serversocket = new ServerSocket(8080);
      } 
      catch(IOException ioe) 
      { 
         System.out.println("Could not create server socket on port 8888. Quitting.");
         System.exit(-1);
      } 
      
      while(On) 
      { 
         try 
         { 
            Socket clientSocket = serversocket.accept();
            ClientServiceThread cliThread = new ClientServiceThread(clientSocket);
            cliThread.start(); 
         } 
         catch(IOException ioe) 
         { 
            System.out.println("Exception found on accept. Ignoring. Stack Trace :"); 
            ioe.printStackTrace(); 
         }  
      } 
   }
	
   public static void main (String[] args) { 
      new RealServer();        
   } 
	
   class ClientServiceThread extends Thread { 
      Socket clientsocket;
      public ClientServiceThread() 
      { 
         super(); 
      } 
		
      ClientServiceThread(Socket s) 
      { 
         clientsocket = s; 
      } 
		
      public void run() 
      {
         System.out.println("Accepted Client Address - " + clientsocket.getInetAddress().getHostName());
      try 
      { 
         PrintWriter networkOut = new PrintWriter(clientsocket.getOutputStream(), true);
         BufferedReader networkIn = new BufferedReader(new InputStreamReader(clientsocket.getInputStream()));
         System.out.println(" Connection established with Client - " + clientsocket.getPort());   
         String message="";
         message = networkIn.readLine();
         while(!message.equals("quit!")) 
         {  
            File dir = new File("./netcen/bbcsport");
            File[] filesList = dir.listFiles();
            int filelength = filesList.length; 
            ArrayList<File> files = new ArrayList<File>(); 
                     
            for(int j=filelength-1;j>0;j--)
            {
               File fe = new File(filesList[j].getPath());
               File[] childs = fe.listFiles();
               for(int i=0;i<childs.length;i++)
               {
                  if((childs[i].getName()).endsWith(".txt") || (childs[i].getName()).endsWith(".WMV"))
                  {
                     files.add(childs[i]);
                  }
               } 
            }
            String file;
            String path;
            int child;
            int count;
            String word;
            ArrayList<String> children = new ArrayList<String>();
            if (files.size() == 0) 
            {
               System.out.println("Either dir does not exist or is not a directory"); 
            } 
            else 
            {    
               for (int i=0;i<files.size();i++) 
               {
                  file=(files.get(i)).getName();
                  path = (files.get(i)).getPath();
                  try
                  {
                     child=0;
                     count=child;
                     InputStream iS = new FileInputStream(files.get(i));
                     BufferedReader br = new BufferedReader(new InputStreamReader(iS));           
                     if(file.contains(message))
                     {
                        children.add(path);
                        child++;
                     }
                     while ((word=br.readLine())!=null && !file.contains(".WMV"))
                     {
                        if(word.contains(message))
                        {
                           if(count==child)
                           {
                              children.add(path);
                              child++;
                           }
                           children.add(word);
                           child++;
                        }
                     }     
                  }
                  catch(Exception io)
                  {
                     System.out.println(io);
                  }
               }
            }
            int ss = children.size();
            String Size = Integer.toString(ss);
            if(children.size()>0)
            {
               networkOut.println(Size);
               for(int i=0;i<children.size();i++)
               {
                  networkOut.println(children.get(i));
               }
               String t = networkIn.readLine();
               int c = Integer.parseInt(t);
               System.out.println(c);
               if(c==2)
               {
                  try
                  {
                     String m = networkIn.readLine();
                                
                     int im=-1;
                     for(int i=0;i<children.size();i++)
                     {
                        if(children.get(i).endsWith(m))
                        {
                           im=i;
                           break;
                        }
                     }
                     if(im!=-1)
                     {
                        System.out.println(children.get(im));
                     }
                     File f = new File(children.get(im));
                     InputStream is = new FileInputStream(f);
                     long s = f.length();
                     int size = (int)s;
                     System.out.println(size);
                     byte []bytes = new byte[size];
                     is.read(bytes);
                     OutputStream out = clientsocket.getOutputStream(); 
                     DataOutputStream dos = new DataOutputStream(out);
                     dos.writeInt(size);
                     if (size > 0) 
                     {
                        dos.write(bytes, 0, size);
                     }  
                  }
                  catch(Exception e)
                  {
                     System.out.println(e);
                  }
               }  
            }
            message = networkIn.readLine();  
         }
      }
      catch(Exception e) 
      { 
         e.printStackTrace(); 
      }
      System.out.println("Client- " + clientsocket.getPort() + " has disconnected");


      } 
   } 
}