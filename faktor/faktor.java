package BDE.faktor;
import java.io.*;
import java.util.*;

public class faktor {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int articles = input.nextInt();
		int faktor = input.nextInt();
		System.out.println(articles * faktor - (articles - 1));
	}

}