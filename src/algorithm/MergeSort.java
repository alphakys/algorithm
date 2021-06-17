package algorithm;

public class MergeSort {

	public static void main(String[] args) {
		
		//두 배열을 비교해서 정렬하는 코드
		int ar[] = {2,4,6,8};
		int ar1[] = {10,5,7,9};
		
		int sort[] = new int[8];
		
		int size = ar.length;
		
		int f = 0;
		int p = 0;
		int i = 0;

		while(f<3 || p<3) {
			
			if(f<ar.length && p<ar.length) {
				if(ar[f] > ar1[p]) {
					
					System.out.println("p--"+p);
					sort[i] = ar1[p];
					System.out.println("p:"+sort[i]);
					i++;p++; 
				}
				else{
					System.out.println("f--"+f);
					sort[i] = ar[f];
					System.out.println("f:"+sort[i]);
					i++;f++;
				}
			}else {
				if(ar[f] > ar1[p]) {
					
					System.out.println("p--"+p);
					sort[i] = ar1[p];
					System.out.println("p:"+sort[i]);
					i++;p++; 
				}
				else{
					System.out.println("f--"+f);
					sort[i] = ar[f];
					System.out.println("f:"+sort[i]);
					i++;f++;
				}
			}
				
			
		
		}
			
		
		
	}

}
