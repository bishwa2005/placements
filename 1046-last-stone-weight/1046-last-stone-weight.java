class Solution {
    public int lastStoneWeight(int[] stones) {
        Queue<Integer>pq = new PriorityQueue<>(Comparator.reverseOrder());

        for(int i : stones){
            pq.offer(i);
        }
        while (pq.size()>1){
                int t1=pq.peek();
                pq.poll();
                int t2=pq.peek();
                pq.poll();

                if((t1-t2)!=0) pq.offer(Math.abs(t1-t2));
        }

        return pq.peek();
    }
}