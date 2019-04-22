import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the boardCutting function below.
    static int boardCutting(long[] cost_y, long[] cost_x) {   //y:horizontal cut, x:vertical cut
        int yl=cost_y.length;
        int xl=cost_x.length;
        int nh=1,nv=1;
        int currX=xl-1,currY=yl-1,curr=0;
        long res=0;
        boolean xOrY=false;
        Arrays.sort(cost_x);
        Arrays.sort(cost_y);
        /*Collections.reverse(Arrays.asList(cost_x));
        Collections.reverse(Arrays.asList(cost_y));*/
        /*for(int i=0;i<xl;i++){
            System.out.println(cost_x[i]);
        }*/
        while(true){
            if(currX==-1 && currY==-1)
                break;
            if(currX>=0 && currY>=0){
                if(cost_x[currX]>cost_y[currY]){
                    curr=currX;
                    currX--;
                    xOrY=false;                    
                }                
                else{
                    curr=currY;
                    currY--;
                    xOrY=true;
                }
                // /System.out.println(xOrY);
            }
            else if(currX==-1){
                curr=currY;
                currY--;
                xOrY=true;
            }           
            else if(currY==-1){
                curr=currX;
                currX--;
                xOrY=false;
            } 
            if(xOrY){
                res+=cost_y[curr]*nv;
                nh++;
            }
            else{
                res+=cost_x[curr]*nh;
                nv++;
            }
            //System.out.println("nh="+nh+",nv="+nv+",res="+res+",currX="+currX+",curY="+currY);
        }        
        return ((int)(res%1000000007));
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String[] mn = scanner.nextLine().split(" ");

            int m = Integer.parseInt(mn[0]);

            int n = Integer.parseInt(mn[1]);

            long[] cost_y = new long[m-1];

            String[] cost_yItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int i = 0; i < m-1; i++) {
                Long cost_yItem = Long.parseLong(cost_yItems[i]);
                cost_y[i] = cost_yItem;
            }

            long[] cost_x = new long[n-1];

            String[] cost_xItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int i = 0; i < n-1; i++) {
                long cost_xItem = Long.parseLong(cost_xItems[i]);
                cost_x[i] = cost_xItem;
            }

            int result = boardCutting(cost_y, cost_x);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
