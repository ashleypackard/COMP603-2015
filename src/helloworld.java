import java.util.Scanner;
public class Helloworld {
public static void main(String[] args) {
Scanner reader = new Scanner(System.in);
char[] arr = new char[30000];
int arrayIndex = 0;
arr[arrayIndex]+=8;
while(arr[arrayIndex]!=0) {
arrayIndex+=1;
arr[arrayIndex]+=4;
while(arr[arrayIndex]!=0) {
arrayIndex+=1;
arr[arrayIndex]+=2;
arrayIndex+=1;
arr[arrayIndex]+=3;
arrayIndex+=1;
arr[arrayIndex]+=3;
arrayIndex+=1;
arr[arrayIndex]+=1;
arrayIndex-=4;
arr[arrayIndex]-=1;
}
arrayIndex+=1;
arr[arrayIndex]+=1;
arrayIndex+=1;
arr[arrayIndex]+=1;
arrayIndex+=1;
arr[arrayIndex]-=1;
arrayIndex+=2;
arr[arrayIndex]+=1;
while(arr[arrayIndex]!=0) {
arrayIndex-=1;
}
arrayIndex-=1;
arr[arrayIndex]-=1;
}
arrayIndex+=2;
System.out.print(arr[arrayIndex]);
arrayIndex+=1;
arr[arrayIndex]-=3;
System.out.print(arr[arrayIndex]);
arr[arrayIndex]+=7;
System.out.print(arr[arrayIndex]);
System.out.print(arr[arrayIndex]);
arr[arrayIndex]+=3;
System.out.print(arr[arrayIndex]);
arrayIndex+=2;
System.out.print(arr[arrayIndex]);
arrayIndex-=1;
arr[arrayIndex]-=1;
System.out.print(arr[arrayIndex]);
arrayIndex-=1;
System.out.print(arr[arrayIndex]);
arr[arrayIndex]+=3;
System.out.print(arr[arrayIndex]);
arr[arrayIndex]-=6;
System.out.print(arr[arrayIndex]);
arr[arrayIndex]-=8;
System.out.print(arr[arrayIndex]);
arrayIndex+=2;
arr[arrayIndex]+=1;
System.out.print(arr[arrayIndex]);
System.out.print(arr[arrayIndex]);
System.out.print(arr[arrayIndex]);
System.out.print(arr[arrayIndex]);
arrayIndex+=1;
arr[arrayIndex]+=2;
System.out.print(arr[arrayIndex]);
}
}
