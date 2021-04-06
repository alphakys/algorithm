package algorithm;

import java.util.ArrayList;
import java.util.Iterator;

public class ProgrammersHash1 {

	public static void main(String[] args) {
		
		String[] par = {"mislav", "stanko", "mislav", "ana"};
		String[] com = {"stanko", "ana", "mislav"};
		
		ArrayList<String> pArr = new ArrayList<>();
		ArrayList<String> cArr = new ArrayList<>();
		
		
		for(String str : com) {
			cArr.add(str);
		}
		
		for(String str1 : par) {
			pArr.add(str1);
		}
		
		for(int i=0; i<cArr.size(); i++) {
			if(pArr.contains(cArr.get(i))) {
				pArr.remove(cArr.get(i));
			}
		}
		
		Iterator<String> itr = pArr.listIterator();
		
		while(itr.hasNext()) {
			System.out.println(itr.next());
		}
		
		
		
	}

}