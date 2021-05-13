package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj1018 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String str[] = br.readLine().split(" ");
		
		int M = Integer.parseInt(str[0]);
		int N = Integer.parseInt(str[1]);
		
		String wChess[][] = new String[8][8];
		
		for(int i=0; i<8; i++) {
			
			for(int j=0; j<8; j++) {
				
				if((i+1)%2 !=0) {
					
					if((j+1)%2!=0) {
						wChess[i][j]="W";
					}else {
						wChess[i][j]="B";
					}
				}else {
					if((j+1)%2!=0) {
						wChess[i][j]="B";
					}else {
						wChess[i][j]="W";
					}
				}
				
			}
		
		}
		/*
		for(int i=0; i<M; i++) {
			
			for(int j=0; j<N; j++) {
				
				System.out.print(wChess[i][j]);
				if(j==N-1) {
					System.out.println();
				}
				
			}
		
		}
		*/
		//System.out.println("-----------------");
		
		String bChess[][] = new String[8][8];
		
		for(int i=0; i<8; i++) {
			
			for(int j=0; j<8; j++) {
				
				if((i+1)%2 !=0) {
					
					if((j+1)%2!=0) {
						bChess[i][j]="B";
					}else {
						bChess[i][j]="W";
					}
				}else {
					if((j+1)%2!=0) {
						bChess[i][j]="W";
					}else {
						bChess[i][j]="B";
					}
				}
				
			}
		
		}
		/*
		for(int i=0; i<8; i++) {
			
			for(int j=0; j<8; j++) {
				
				System.out.print(bChess[i][j]);
				if(j==N-1) {
					System.out.println();
				}
				
			}
		
		}
		
		System.out.println("===================");
		*/
		
		int wCount = 0;
		int bCount = 0;
		
		String ex[][] = new String[M][N];
		
		for(int i=0; i<M; i++) {
			
			String stArr[] = br.readLine().split("");
			
			for(int j=0; j<N; j++) {
				/*
				System.out.print(stArr[j]);
				if(j==N-1) {
					System.out.println();
				}
				*/
				ex[i][j] =stArr[j];
				
			}
		
		}
		
		for(int x=0,a=0; a<8; x++, a++) {
			
			for(int y=0,b=0; b<8; y++, b++) {
				
				if(wChess[a][b].equals(ex[x][y])) {
					wCount++;
				}
			}
		}
		
		
		
		
		
		System.out.println(wCount);
		System.out.println(bCount);
		
		
	}

}
