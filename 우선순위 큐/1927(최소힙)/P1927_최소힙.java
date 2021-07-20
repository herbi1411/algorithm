import java.util.ArrayList;
import java.util.Scanner;

public class P1927_최소힙 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		ArrayList<Integer> arr = new ArrayList<Integer>();
		ArrayList<Integer> heap = new ArrayList<Integer>();
		heap.add(-1);
		int N = input.nextInt();
		
		for(int i =0; i<N; i++) arr.add(input.nextInt());
		
		for(int i =0; i<N; i++) {
				if(arr.get(i) == 0)
					System.out.println(popValue(heap));
				else
					insertValue(heap,arr.get(i));
		}
		
	}

	private static void insertValue(ArrayList<Integer> heap, Integer value) {
		// TODO Auto-generated method stub
		int index = heap.size();
		heap.add(value);
		while(index > 1) {
			int parent = index / 2;
			if(heap.get(parent) > value)
				heap.set(index, heap.get(parent));
			else
				break;
			index = parent;
		}
		heap.set(index, value);
	}

	private static Integer popValue(ArrayList<Integer> heap) {
		// TODO Auto-generated method stub
		if(heap.size() == 1)
			return 0;
		int rt = heap.get(1);
		int index = 1;
		heap.set(1, heap.get(heap.size()-1));
		heap.remove(heap.size()-1);
		while(index <= (heap.size() - 1) / 2) {
			int left = index * 2;
			int right = index * 2 + 1;
			if(right >= heap.size()) { //left만 존재
				if(heap.get(left) < heap.get(index)) {
					swap(heap,left,index);
					index = left;
				}
				else
					break;
			}
			else { //left, right 모두 존재
				if(heap.get(left)<=heap.get(right)) {
					if(heap.get(left)<heap.get(index)) {
						swap(heap,left,index);
						index = left;
					}
					else
						break;
				}
					else {
						if(heap.get(right)<heap.get(index)) {
							swap(heap,right,index);
						index = right;
						}
						else
							break;
					}
			}
		}
		return rt;
	}

	private static void swap(ArrayList<Integer> heap, int left, int index) {
		// TODO Auto-generated method stub
		int temp = heap.get(left);
		heap.set(left, heap.get(index));
		heap.set(index, temp);
	}

}
