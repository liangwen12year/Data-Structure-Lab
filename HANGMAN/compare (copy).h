
int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string){
	int lSize,rSize,minSize,matches;
	char *lString, *rString;
	My_string* pLeft_string = (My_string*)hLeft_string;
	My_string* pRight_string = (My_string*)hRight_string;
	lSize=my_string_get_size(hLeft_string);
	rSize=my_string_get_size(hRight_string);
	minSize=(lSize<rSize)?lSize:rSize;
	lString=((struct My_string*) hLeft_string)->c_string;
	rString=((struct My_string*) hRight_string)->c_string;
	for(matches=0;matches<minSize;matches++){
	 if(*lString!=*rString){
		break;
	     }else{
		   lString++;
		   rString++;
	     }
	    if(matches == minSize)
			if(lSize == rSize)
				return 0;
			else if(lSize<rSize)
				return -matches;
			else 
				return matches;

	   else
		        return *lString<*rSring ?-1 :1;

}


