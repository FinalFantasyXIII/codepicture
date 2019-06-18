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
