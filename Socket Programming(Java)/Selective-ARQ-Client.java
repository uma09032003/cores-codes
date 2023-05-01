//Kindly ignore the file name and note that different name has been used for the class
import java.io.*;
import java.util.*;
import java.lang.*;
import java.net.*;

public class clientSNRQ{
  //Class name is different from the file name
	public static void main(String[] args){
		try{
		Socket s=new Socket("localhost",1555);
		DataInputStream di=new DataInputStream(s.getInputStream());
		DataOutputStream dou=new DataOutputStream(s.getOutputStream());

		//Selective Repeat Request N - ARQ
		//Server Window Size = Client Window Size 
		// Window size is always greater than 1
		//Only the lost frame is resent


		String[] message={"Hi 0","Hello 1","This 2","is 3","Idiot 4","Programmer 5"};

		//To simplify the coding design let's alter the loop structure derive the window functionality 
		//In the first pass, all the 2 initial messages will be sent without acknowledgement 
		//From the next, it will wait for Acknowledgement
		//Actually, ARQ to be done using Threads in Java
		//To simplify the design, UNS -> unsend/missed ACK -> Acknowledgement NACK - No Acknowledgement

		//Sending 1st Window filled Frame
		int i=0;
		for (i=0;i<2;i++){
			dou.writeUTF(message[i]);
			di.readUTF();
		}
		int seq=0;
		while(seq<6){
			String st=(String)di.readUTF();
			
			if(st.charAt(0)=='A' && ((int)(st.charAt(st.length()-1))-48)==seq){
				System.out.println("Received Acknowledgement for "+seq);
				if(i<6){
					if(i==3){
						dou.writeUTF("UNS "+i);
						System.out.println("Missed Sending "+i);
					}
					else{
				dou.writeUTF(message[i]);
				System.out.println("Sent "+i);			}
			}
				i++;
				seq++;
				
			}
			else if(st.charAt(0)=='N'){
				dou.writeUTF(message[(int)st.charAt(st.length()-1)-48]);
				System.out.println("Resending "+ ((int)st.charAt(st.length()-1)-48));
			}
		}

		System.out.println("All Frames sent Successfully");
		s.close();
//Contributed by the theProgrammerIdioticCoder

}catch(Exception e){
	System.out.println(e);
	}
}
}
