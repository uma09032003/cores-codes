import java.io.*;
import java.util.*;
import java.net.*;

public class simpleChatClient{
	public static void main(String[] args){
		try{
		Socket s=new Socket("localhost",1500);
		DataInputStream dt=new DataInputStream(s.getInputStream());
		DataOutputStream doU=new DataOutputStream(s.getOutputStream());
		Scanner sc=new Scanner(System.in);

		System.out.println("Server Waiting for Response ! . . . .");
		doU.writeUTF(sc.nextLine());

		while(true){
			
			String st=(String)dt.readUTF();
			if(st.equals("Bye")){
				break;
			}
			System.out.println(st);
			System.out.println("Server Waiting for Response ! . . . .");
		    doU.writeUTF(sc.nextLine());
		}
		System.out.println("Session Ended!");
		s.close();
	}catch (Exception e){
		System.out.println(e);
	}

	}
}
