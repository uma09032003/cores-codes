//Kindly ignore the file name and note that different name has been used for the class

import java.io.*;
import java.lang.*;
import java.util.*;
import java.net.*;

public class serverSNRQ{
  //Name of the Class id serverSNRQ
	public static void main(String[] args){
		try{
		ServerSocket sr=new ServerSocket(1555);
		Socket s=sr.accept();
		System.out.println("Accepted Client Connection \n");

		DataInputStream di=new DataInputStream(s.getInputStream());
		DataOutputStream dou=new DataOutputStream(s.getOutputStream());

		String[] received={"No","No","No","No","No","No"};
		int seq=0;
		
		for(int i=0;i<2;i++){
			String st=(String)di.readUTF();
			int k=(int)st.charAt(st.length()-1);
			k=k-48;
			received[k]=st;
			//System.out.println("Received Frame"+k);
			dou.writeUTF("Next");
		}
		

		while(seq<6){ 
        
        if(!(received[seq].equals("No")||received[seq].equals("UNS "+seq))) {
        	dou.writeUTF("ACK "+String.valueOf(seq));
        	System.out.println("Acknowledged "+seq);
        	if(received[5].equals("No")){
        	String st=(String)di.readUTF();
        	int k=(int)st.charAt(st.length()-1);
        	received[k-48]=st;
        	System.out.println("Received "+(k-48));}
        	seq++;
        }
        else{
        	dou.writeUTF("NACK "+String.valueOf(seq));
        	System.out.println("Missed "+seq);
        	String st=(String)di.readUTF();
        	int k=(int)st.charAt(st.length()-1);
        	received[k-48]=st;
        }
    }
    System.out.println("Message recieved from the client : ");
    for (int i=0;i<6;i++){
    	System.out.println(received[i]);
    }
    //Contributed by the theProgrammerIdioticCoder
    s.close();
}
catch (Exception e){
	System.out.println(e);
}
}
}
