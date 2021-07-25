package algorithm;

import java.io.IOException;

public class Practice {
		
		int value;
	
		Practice(int v){
			this.value = v;
		}
		
		public static void swap(Practice a, Practice b) {
			System.out.println(System.identityHashCode(a.value));
			System.out.println(System.identityHashCode(b.value));
			System.out.println(a.value + b.value);
			int temp = a.value;
			a.value = b.value;
			b.value = temp;
			System.out.println(a.value + b.value);
			System.out.println(System.identityHashCode(a.value));
			System.out.println(System.identityHashCode(b.value));
			System.out.println(a.value + b.value);
		}
		
	public static void main(String[] args)throws IOException {
		
		Practice a = new Practice(10);
		Practice b = new Practice(-20);
		
		//System.out.println(a.value +" "+ b.value);
		//System.out.println(a.value+b.value);
		swap(a, b);
		
		//System.out.println(a.value +" "+ b.value);
	}
	

}