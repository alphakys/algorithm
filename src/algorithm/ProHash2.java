package algorithm;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map.Entry;

public class ProHash2 {

	public static void main(String[] args) {
		
		String[] phone_book = {"1192456", "119"};
		String[] phone_book1 = {"123","456","789"};
		String[] phone_book2 = {"12","123","1235","567","88"};
		
		HashMap<String, Boolean> map = new HashMap<>();

		boolean answer =true;
		
		for(int i=1; i<phone_book.length;i++) {
			
			if(phone_book[0].length()>phone_book[i].length()) {
				map.put(phone_book[i], true);
			}else {
				answer = !phone_book[i].substring(0, phone_book[0].length()).equals(phone_book[0]);
			
				map.put(phone_book[i], answer);
			}
			
			
			
		}
		
		for(Entry<String, Boolean> entry : map.entrySet()) {
			
			if(entry.getValue()==false) {
				System.out.println(false);
				return;
			}
		}
		
		System.out.println(answer);
	
		
		
	}

}
