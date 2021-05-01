package algorithm;

import java.io.IOException;
import java.util.HashSet;
import java.util.Iterator;

public class Boj4673 {

	public static void main(String[] args)throws IOException {
		
		HashSet<Integer> hansu = new HashSet<>(13000);
		HashSet<Integer> all = new HashSet<>(13000);
		
		for(int i=1;i<=10000 ;i++) {
			all.add(i);
			
			if(i<10) {
				hansu.add(i+i);
				
			}else if(i<100) {
				
				hansu.add((i/10)+(i%10)+i);
			}else if(i<1000) {
				hansu.add((i/100)+((i/10)%10)+(i%10)+i);
			}else {
				int num = ((i/100)/10)+((i/100)%10)+((i%100)/10)+((i%100)%10)+i;
				
				if(num<=10000) {
					hansu.add(num);
				}
				
			}
			
		}
		
		all.removeAll(hansu);
		Iterator<Integer> itr = all.iterator();
		
		while(itr.hasNext()) {
			System.out.println(itr.next());
		}
	
	}

}
