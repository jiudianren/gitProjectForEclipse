https://www.smwenku.com/a/5b89969c2b71775d1ce29969



? ??两个CPU核分配任务问题：

? ? 给定n(0~N)个任务work，每个任务i=0~n-1都有各自需要处理的时间needTime[i] =1~1000(ms)。另外有两个CPU核（核A、核B）处理这些任务，将n个任务分配给两个CPU核，求这两个核处理完所有给定任务所需要的最短时间。

其中，每个任务只能分配给一个核进行处理，且只被能处理一次。每个CPU核同一时间只能处理一个任务。

例如，输入needTime[5] = {5,5,5,7,7}；五个任务，分配结果是5+5+5=15(ms)，7+7=14(ms)，最终输出15。两个CPU核在15ms内处理完所有任务。



? ? 解决思路：首先随机设计一种“任务分配方案”，然后再不断交换两个核内分配的某些任务，使结果不断优化，直至得到最优解，最后输出结果。该思路来源于《算法导论》第26章最大流的增广路径的反方向调度的思想。

? ? 具体过程：首先随机得到一种分配方案——核A:5+7=12，核B:5+5+7=17。核B -?核A = 5，寻找在核B中的某任务的需求时间b 与 核A中的某任务的需求时间a，满足 0 < b-a < 核B -?核A。目前，核B中有个任务的需求时间为 7 ，核A中的有个任务的需求时间为 5 ，7-5=2 <?核B -?核A，交换核A和核B的这两个任务，得到一种更优的新的任务分配方案，核A:7+7=14，核B:5+5+5=15。此时，核B -?核A = 1，在核B中的所有任务 与 核A中的所有任务，无法满足 0 < b-a <?核B -?核A，停止寻找，输出15。

? ? 停止的判断条件，即获得最优解的条件，是无法在核A中的所有任务 与 核B中的所有任务 中找到满足“?0 < a-b <?核A -?核B ”或“?0 < b-a <?核B -?核A?”。这个结论用一句话来证明：如果 ?在核A中的所有任务 与 核B中的所有任务 中找到满足“?0 < a-b <?核A -?核B?”或“?0 < b-a <?核B -?核A?”的情况，当前的分配方案一定可以通过交换两个任务得到更优的分配方案。注：设a==0或b==0的任务为“空任务”，我们认为“空任务”，也是可交换的任务，核A和核B中都有无数个“空任务”。



	int func(vector<int> &nums) 
	{
		nums.push_back(0);// 添加 执行时间为 0 的任务，为了便于求单个任务的执行时间
		int len = nums.size();
		quickSort(nums, 0, len - 1);// 快速排序，从小到大
		unordered_map<int, vector<pair<int, int> > > mapping;// 声明一个 hashmap，用于存储两个任务的差
		for (size_t fir = 0; fir < len; fir++)
			for (size_t sec = fir + 1; sec < len; sec++)
				mapping[nums[sec] - nums[fir]].push_back(pair<int, int>(fir, sec));// 存储两个任务的差，其中 second >= first，即 second 任务执行时间 不少于 first 任务执行时间
	 
		int t_A = 0, t_B = 0;// 记录各CPU的当前总执行时间
		vector<int> mark;// 声明一个标记，用来标记任务的分配情况
		mark.push_back(0);// 第一个执行时间为 0 的任务，不分配，标记为 0
		for (int i = 1; i < len / 2; i++) 
		{
			mark.push_back(1);// 分配给CPU-A，标记为 1
			t_A += nums[i];
		}
		for (int i = len / 2; i < len; i++) 
		{
			mark.push_back(-1);// 分配给CPU-B，标记为 -1
			t_B += nums[i];
		}
		int d_t = abs(t_A - t_B);// 两个CPU的总执行时间的差
		const int s_t = t_A + t_B;// 两个CPU的总执行时间的和
		int flag = 1;// 增广方案 是否存在的标记，1 表示存在，0 表示不存在
	 
		// 不断寻找两个CPU的增广方案，当找不到增广方案时 flag == 0，说明达到最优解，停止while循环
		while (flag) 
		{
			flag = 0;
			for (int t = d_t - 1; t > 0; t--) 
			{
				if (mapping.find(t) == mapping.end()) continue;// 没有 ==t 的增广方案，进行下一步 t-1 的增广方案的寻找
				const auto& vec = mapping[t];
				for (int k = 0; k < vec.size(); k++) 
				{
					// 存在 ==t 的增广方案，并且该方案中 first == 0，只有一个任务，且该任务在总执行时间较大的CPU的分组中
					if (vec[k].first == 0 
						&& mark[vec[k].second] * (t_A - t_B) > 0) 
					{
						mark[vec[k].second] *= -1;// 转移该任务的分组
						t_A += mark[vec[k].second] * nums[vec[k].second];
						t_B = s_t - t_A;
						flag = 1;// 找到增广方案，设置为 1
						break;
					}
					// 存在 ==t 的增广方案，执行时间较大的任务 在总执行时间较大的CPU的分组中，且执行时间较小的任务 在总执行时间较小的CPU的分组中，交换这两个任务
					if (vec[k].first != 0 
						&& mark[vec[k].second] * (t_A - t_B) > 0 
						&& mark[vec[k].first] * mark[vec[k].second] == -1) 
					{
						mark[vec[k].first] *= -1;// 转移该任务的分组
						mark[vec[k].second] *= -1;// 转移该任务的分组
						t_A += mark[vec[k].first] * nums[vec[k].first];
						t_A += mark[vec[k].second] * nums[vec[k].second];
						t_B = s_t - t_A;
						flag = 1;// 找到增广方案，设置为 1
						break;
					}
				}
				if (flag == 1) break;// 找到增广方案
			}
			d_t = abs(t_A - t_B);// 重新计算 两个CPU的总执行时间的差
		}
	 
		return (t_A > t_B) ? t_A : t_B;
	}

