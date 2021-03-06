#include<gtk/gtk.h>
void fun(GtkButton *button,gpointer userdata){
	char *a=(char *)userdata;
	printf("%s\n",a);
}
int main(int argc, char  *argv[])
{
	gtk_init(&argc,&argv);
	char string[]="linux";
	gchar *title=string;
    GtkWidget *button=gtk_button_new_with_label("button");
	GtkWidget *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),title);
    gtk_widget_set_size_request(window,320,220);
    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
	gtk_container_add(GTK_CONTAINER(window),button);
	g_signal_connect(button,"pressed",G_CALLBACK(fun),string);
	gtk_widget_show_all(window);
	gtk_main(); 
	return 0;
}
