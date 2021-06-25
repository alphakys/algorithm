package algorithm;

public class MergeSort {
	
	public static int[] array;
	public static int[] tmp;
	
	public static void main(String[] args) {
		
		array = new int[]{1, 9, 8, 5, 4, 2, 3, 7, 6, 10}; 
		tmp = new int[array.length];
		
		//index(start, end)
		mergeSort(0, array.length-1);
		// 		 (0, 7)

		
		
	}
// 9/2 --> 4 0~4;
		
	public static void mergeSort(int start, int end) {
	
		if(start<end) {
			
			int mid = (start+end)/2;
								   // 1			2		  		3							4
			mergeSort(start, mid); //(0, 4) --> (0,2),(3,4) --> (0,1)(2,2),,(3,3)(4,4) --> (0,0),(1,1)
			mergeSort(mid+1, end); //(5, 9) --> (5,7)(8,9) --> (5,6)(7,7),,(8,8)(9,9) --> (5,5),(6,6)
			
			int p = start;
			int q = end;
			int idx = 1;
			
			while(true) {
				
				if(array[p]== array[q]) {
					tmp[p] = array[p];
					
				}else {
					
					if(array[p]>array[q])
						tmp[q] = array[p];
						tmp[p] = array[q];
				}
			}
			
			
			
			
			
			
		}
	 


	}	
		
		
		
}	
		
		/*
		while(i<8) {
			
			//한 배열이 먼저 배열의 끝에 도달했다면 그 다음엔 어떻게 처리해줘야 하나?
			if(f==size && p<size1) {
				
			}
			

			if(f<ar.length-1 && p<ar.length-1) {
				if(ar[f] > ar1[p]) {
					
					System.out.println("p:"+p);
					sort[i] = ar1[p];
					System.out.println("value:"+sort[i]);
					i++;p++; 
				}
				else{
					System.out.println("f:"+f);
					sort[i] = ar[f];
					System.out.println("value:"+sort[i]);
					i++;f++;
				}
			}else {
				if(ar[f] > ar1[p]) {
					
					System.out.println("2p:"+p);
					sort[i] = ar1[p];
					System.out.println("value2:"+sort[i]);
					sort[i+1] = ar[f];
					break;
				}
				else{
					System.out.println("2f:"+f);
					sort[i] = ar[f];
					System.out.println("value2:"+sort[i]);
					sort[i+1] = ar[p];
					break;
				}
			}
				
			
		
		}
		*/	