import java.util.Scanner;
public class BrainfuckMain {
public static void main(String[] args) {
Scanner reader = new Scanner(System.in);
char[] arr = new char[30000];
int arrayIndex = 0;
arr[arrayIndex]++;
while(arr[arrayIndex]!=0) {
arrayIndex++;
arr[arrayIndex] = reader.next().charAt(0);
System.out.print(arr[arrayIndex]);
arrayIndex--;
}
}
}
