/*
* 这样子的夫妻结构体可以进行拓展改进，可以根据需求把里面的单一指针改成数组或链表
* 这样改进可以让两个结构体由 一对一模式变成 n对n模式
* 再把结构体成员全部变为公有，根据一些配置控制 数组链表里其他对象对本结构体的访问权限。
* 这样就可以用于一些朋友圈等方面
*/
struct wife;
struct husban {
	string name;
	int age;
	wife* w;
};
struct wife {
	string name;
	int age;
	husban* h;
};
void show() {
	husban jack{ "jack",28,nullptr };
	wife rose{ "rose",26,nullptr };
	jack.w = &rose;
	rose.h = &jack;

	cout << jack.name << "-" << jack.age << "-" << jack.w->name << endl;
	cout << rose.name << "-"<< rose.age << "-" << rose.h->name << endl;
}
