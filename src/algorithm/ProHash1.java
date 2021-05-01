package algorithm;

import java.util.HashMap;
import java.util.Map.Entry;

public class ProHash1 {

	public static void main(String[] args) {
		String[] participant = {"mislav", "stanko", "mislav", "ana"};
		
		String[] completion = {"stanko", "ana", "mislav"};
		
		HashMap<String, Integer> map = new HashMap<>();
		
		for(String part : participant) {
			
			map.put(part, map.getOrDefault(part, 0)+1);
		}
		
		
		for(String com : completion) {
			
			map.put(com, map.get(com)-1);
		}
		
		String answer="";
		
		for(Entry<String, Integer> entry : map.entrySet()) {
			
			if(entry.getValue()>0) {
				
				 answer = entry.getKey();
			}
		}
		
		System.out.println(answer);
		
	}

}
