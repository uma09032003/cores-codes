//Kindly ignore the file name and note that different name has been used for the class

import java.io.*;
import java.lang.*;
import java.util.*;
import java.net.*;

public class fileSendClient{
	public static void main(String[] args){
		try{
		Socket s=new Socket("localhost",1555);
		DataOutputStream dou=new DataOutputStream(s.getOutputStream());
		DataInputStream di=new DataInputStream(s.getInputStream());

		File f=new File("textFile(From-Cline).txt");
		FileWriter m=new FileWriter("textFile(From-Cline).txt");
		String st=(String)di.readUTF();
		while(!st.equals("EOF")){
			m.write(st);
			m.write("\n");
			dou.writeUTF("AAAA");
			st=(String)di.readUTF();
		}
		System.out.println("File Transfer Successful !");
		m.close();
		s.close();

	}catch(Exception e){
		System.out.println(e);
	}

} 
}
