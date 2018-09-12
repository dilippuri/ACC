public class TextJustification {

    public String justify(String words[], int width) {
        
        int cost[][] = new int[words.length][words.length];
        
        //next 2 for loop is used to calculate cost of putting words from
        //i to j in one line. If words don't fit in one line then we put
        //Integer.MAX_VALUE there.
        for(int i=0 ; i < words.length; i++){
            cost[i][i] = width - words[i].length();
            for(int j=i+1; j < words.length; j++){
                cost[i][j] = cost[i][j-1] - words[j].length() - 1; 
            }
        }
        
        for(int i=0; i < words.length; i++){
            for(int j=i; j < words.length; j++){
                if(cost[i][j] < 0){
                    cost[i][j] = Integer.MAX_VALUE;
                }else{
                    cost[i][j] = (int)Math.pow(cost[i][j], 2);
                }
            }
        }
        for(int i=0; i < words.length; i++){
            for(int j=0; j < words.length; j++){
				System.out.print(cost[i][j]+ " ");
			}System.out.println();
		}System.out.println();
       //minCost from i to len is found by trying
        //j between i to len and checking which
        //one has min value
        int minCost[] = new int[words.length];
        int result[] = new int[words.length];
		System.out.println("calculation"+words.length);
        for(int i = words.length-1; i >= 0 ; i--){
            minCost[i] = cost[i][words.length-1];
            result[i] = words.length;
			System.out.println("minCost "+minCost[i]+"result "+result[i]);
            for(int j=words.length-1; j > i; j--){
			System.out.println("cost1 "+cost[i][j-1]);
                if(cost[i][j-1] == Integer.MAX_VALUE){
				System.out.println("continue");
                    continue;
                }
                if(minCost[i] > minCost[j] + cost[i][j-1]){
                    minCost[i] = minCost[j] + cost[i][j-1];
                    result[i] = j;
                }
            }
        }
        int i = 0;
        int j;
		for(i=0;i<words.length;i++){
		System.out.print(result[i]+" ");}
		i=0;
        System.out.println("\nMinimum cost is " + minCost[0]);
        System.out.println("\n");
        //finally put all words with new line added in 
        //string buffer and print it.
        StringBuilder builder = new StringBuilder();
        do{
            j = result[i];
            for(int k=i; k < j; k++){
                builder.append(words[k] + " ");
            }
            builder.append("\n");
            i = j;
        }while(j < words.length);
        
        return builder.toString();
    }
    
    public static void main(String args[]){
        String words1[] = {"student","svnit","acc","course","dilip","not","to","write","letter"};
        TextJustification awl = new TextJustification();
        System.out.println(awl.justify(words1, 10));
    }
}
