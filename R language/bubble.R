a = scan()
9 1 2 3 -1 2 -3  

bubblesort <- function(a) {
	swap = TRUE;
	while(swap){
		swap = FALSE;
		for(i in 1:(length(a) - 1)){
			if (a[i]> a[i+1]){
				swap = TRUE;
				temp = a[i];
				a[i]=a[i+1];
				a[i+1]= temp;
			}
		}
	}

	print(a);
}
bubblesort(a)