import java.io.*;
import java.net.*;
import java.util.*;

public class simpleChatServer{
	public static void main(String[] args){
		try{
		ServerSocket sr=new ServerSocket(1500);
		Socket ss=sr.accept();
		DataInputStream dt=new DataInputStream(ss.getInputStream());
		DataOutputStream doU=new DataOutputStream(ss.getOutputStream());

		

		while(true){
			String st=(String)dt.readUTF();
			if(st.equals("End")){
				doU.writeUTF("Bye");
				break;
			}
			if(st.equals("Hi")){
				doU.writeUTF("Hi!, Glad to inform you that you established a connection to me \n I am the Server!");
			}
			else if(st.equals("How are you ?")){
				doU.writeUTF("I am fine!");
			}
		}
		ss.close();
	} catch(Exception e){
		System.out.println(e);
	}

	}
}
