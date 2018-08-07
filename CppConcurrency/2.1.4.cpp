
void update_data_for_widget(widget_id w,widget_data& data); // 1
void oops_again(widget_id w)
{
	widget_data data;
	std::thread t(update_data_for_widget,w,data); // 2
//	std::thread t(update_data_for_widget,w,std::ref(data));
	display_status();
	t.join();
	process_widget_data(data); // 3
}
