#include <iostream>
#include <vector>

class ZigZag {
	public :
		int longestZigZag (std::vector<int> v) {
			int len = v.size();
			if (len == 0)
				return 0;
			if (len == 1)
				return 1;
			int * d = new int[len];
			for (int i = 0; i < len; ++i) 
				d[i] = 1;
			int max = 0;
			
			for (int i = 1; i < len; ++i ) {
				for (int k = 0; k < i; ++k ) {
					if ((k == 0 && v[k] != v[i])|| (v[k-1] < v[k] && v[k] > v[i]) || (v[k-1] > v[k] && v[k] < v[i])) {
						d[i] = std::max (d[i], d[k] + 1);
						if (max < d[i] ) {
							max = d[i];
						}
					}
				}
			}
			delete [] d;
			return max;
		}
};
