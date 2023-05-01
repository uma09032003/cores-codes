//Kindly ignore the file name and note that different name has been used for the class

import java.io.*;
import java.util.*;
import java.lang.*;
import java.net.*;

public class fileSendServer{
	public static void main(String[] args){
		try{
		ServerSocket sr=new ServerSocket(1555);
		Socket s=sr.accept();

		DataInputStream di=new DataInputStream(s.getInputStream());
		DataOutputStream dou=new DataOutputStream(s.getOutputStream());

		System.out.println("Client Connection Accepted ! ");

		File file=new File("textFile.txt");
		Scanner sc1=new Scanner(file);
		while(sc1.hasNextLine()){
			String st=sc1.nextLine();
			dou.writeUTF(st);
			di.readUTF();
		}
		dou.writeUTF("EOF");
		sc1.close();
		System.out.println("File Transferred Sucessfully !");
		s.close();
	}catch(Exception e){
		System.out.println(e);
	}

	}
}
