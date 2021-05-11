#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<fstream.h>
#include<dos.h>
#include<process.h>
class ciphers
{	public:
	void caesar();
	void atbash();
	void a1z26();
	void combined();
	void vigenere();
	void polybius();
	void binary();
};
void filestore(char content[77])
{       cout<<"\n Would you like to save this result in a file? \n";
	char str[7];
	for(int i=1;i>0;i++)
	{	gets(str);
		for(int j=0;j<strlen(str);j++)
			str[j]=tolower(str[j]);
		if(strcmp(str,"yes")==0)
		{	cout<<"\n Enter the file name \n";
			char fname[77];
			gets(fname);
			fstream fout(fname,ios::in);
			if(!fout)
			{       fout.close();
				fout.open(fname,ios::out);
				fout<<content;
				cout<<"\n Done \n";
				break;
			}
			else
			{	for(int k=1;k>0;k++)
				{	cout<<"\n A file with this name exists. Would you like to overwrite it(overwrite), \n make a new file(newfile), rather not save(dontsave) \n or would you like to read this file(readit)? \n";
					char a[14];
					gets(a);
					for(int l=0;l<strlen(a);l++)
						a[l]=tolower(a[l]);
					if(strcmp(a,"overwrite")==0)
					{       fout.close();
						fout.open(fname,ios::in|ios::out|ios::trunc);
						fout<<content;
						cout<<"\n Done \n";
						break;
					}
					else if(strcmp(a,"newfile")==0)
					{       cout<<"\n Enter the new file name \n";
						gets(fname);
						fout.close();
						fout.open(fname,ios::in);
						if(!fout)
						{       fout.close();
							fout.open(fname,ios::out);
							fout<<content;
							cout<<"\n Done \n";
							break;
						}
						else
							continue;
					}
					else if(strcmp(a,"dontsave")==0)
						break;
					else if(strcmp(a,"readit")==0)
					{	char ch;
						cout<<"Contents of the file are: \n";
						while(!fout.eof())
						{	fout.get(ch);
							cout<<ch;
						}
						cout<<endl;
						continue;
					}
					else
					{	cout<<"\n Try again \n";
						continue;
					}
				}
				break;
			}
			fout.close();
		}
		else if(strcmp(str,"no")==0)
			break;
		else
			cout<<"Try again. Enter yes or no. \n";
	}
}
void ciphers::caesar()
{       int n;char message[77];char code[77];
	cout<<"\n How many letters? \n";
	for(int a=1;a>0;a++)
	{	cin>>n;
		if(n>=0 && n<=26)
		{	cout<<"\n Encrypt or Decrypt? \n";
			char choice[14];
			for(int j=1;j>0;j++)
			{	gets(choice);
				for(int i=0;i<strlen(choice);i++)
					choice[i]=tolower(choice[i]);
				if(strcmp(choice,"encrypt")==0)
				{	cout<<"\n Enter the message \n";
					gets(message);
					for(i=0;i<strlen(message);i++)
					{       if(message[i]<65 || message[i]>122 || message[i]>90 && message[i]<97)
							code[i]=message[i];
						else if(message[i]>64 && message[i]<91)
						{	if(message[i]+n>90)
								code[i]='A'+n-(91-message[i]);
							else
								code[i]=message[i]+n;
						}
						else if(message[i]>96 && message[i]<123)
						{	if(message[i]+n>122)
								code[i]='a'+n-(123-message[i]);
							else
								code[i]=message[i]+n;
						}
					}
					code[strlen(message)]='\0';
					cout<<"The caesar "<<n<<"-letter code is : \n"<<code<<endl;
					filestore(code);
					break;
				}
				else if(strcmp(choice,"decrypt")==0)
				{	cout<<"\n Enter the code \n";
					gets(code);
					for(i=0;i<strlen(code);i++)
					{       if(code[i]<65 || code[i]>122 || code[i]>90 && code[i]<97)
							message[i]=code[i];
						else if(code[i]>64 && code[i]<91)
						{	if(code[i]-n<65)
								message[i]='Z'-n+(code[i]-64);
							else
								message[i]=code[i]-n;
						}
						else if(code[i]>96 && code[i]<123)
						{	if(code[i]-n<97)
								message[i]='z'-n+(code[i]-96);
							else
								message[i]=code[i]-n;
						}
					}
					message[strlen(code)]='\0';
					cout<<"The message in the caesar "<<n<<"-letter code is : \n"<<message<<endl;
					filestore(message);
					break;
				}
				else
					cout<<"Try again. Enter encrypt or decrypt. \n";
			}
			break;
		}
		else
			cout<<"Try again. Enter a number between 0 and 26. \n";
	}

}
void ciphers::atbash()
{       cout<<"\n Enter the string \n";
	char a[77];
	gets(a);
	for(int i=0;i<strlen(a);i++)
	{	if(a[i]>=65&&a[i]<=90)
			a[i]=90-(a[i]-65);
		if(a[i]>=97&&a[i]<=122)
			a[i]=122-(a[i]-97);
	}
	cout<<"\n The atbash form is: \n";
	puts(a);
	filestore(a);
}
void ciphers::a1z26()
{       char message[77],code[77];
	cout<<"\n Encrypt or decrypt? \n";
	char choice[14];
	for(int j=1;j>0;j++)
	{	gets(choice);
		for(int i=0;i<strlen(choice);i++)
			choice[i]=tolower(choice[i]);
		if(strcmp(choice,"encrypt")==0)
		{	cout<<"\n Enter the message \n";
			gets(message);
			for(int x=0,i=0;x<strlen(message);x++)
			{	if(isalpha(message[x]))
				{       int a=toupper(message[x])-64;
					if(toupper(message[x])<'J')
					{	code[i]=a+48;
						i++;
					}
					else
					{	int n=a/10;
						n+=48;
						code[i]=n;
						i++;
						n=a%10;
						n+=48;
						code[i]=n;
						i++;
					}
					if(isalpha(message[x+1]))
					{	code[i]='-';
						i++;
					}
				}
				else
				{	code[i]=message[x];
					i++;
				}
			}
			code[i]='\0';
			cout<<"\n The A1Z26 code is: \n"<<code;
			filestore(code);
			break;
		}
		else if(strcmp(choice,"decrypt")==0)
		{       int b,c,d,e;
			char g;
			cout<<"\n Enter the code \n";
			gets(code);
			b=0;e=0;
			while(code[b]!='\0')
			{
				c=0;
				while(code[b]>47 && code[b]<58)
				{
					d=(int) code[b];
					d-=48;
					c=c*10+d;

					b++;
				}
				if(code[b-1]>47 && code[b-1]<58)
				{	g=(char) c+64;
					message[e]=g;
					e++;
				}
				if(code[b]<48 && code[b]!='-' || code[b]>57 && code[b]!='-')
				{	message[e]=code[b];
					e++;
				}
				if(code[b]!='\0')
					++b;
			}
			cout<<"\n The message hidden in the A1Z26 code is: \n"<<message;
			filestore(message);
			break;
		}
		else
			cout<<"Try again. Enter encrypt or decrypt. \n";
	}
}
void ciphers::combined()
{       int n;char message[77];char code[77];
	cout<<"\n How many letters of caesar? \n";
	for(int a=1;a>0;a++)
	{	cin>>n;
		if(n>=0 && n<=26)
		{	cout<<"\n Encrypt or decrypt? \n";
			char choice[14];
			for(int j=1;j>0;j++)
			{	gets(choice);
				for(int i=0;i<strlen(choice);i++)
					choice[i]=tolower(choice[i]);
				if(strcmp(choice,"encrypt")==0)
				{	cout<<"\n Enter the message \n";
					gets(message);
					for(i=0;i<strlen(message);i++)
					{       if(message[i]<65 || message[i]>122 || message[i]>90 && message[i]<97)
							code[i]=message[i];
						else if(message[i]>64 && message[i]<91)
						{	if(message[i]+n>90)
								code[i]='A'+n-(91-message[i]);
							else
								code[i]=message[i]+n;
						}
						else if(message[i]>96 && message[i]<123)
						{	if(message[i]+n>122)
								code[i]='a'+n-(123-message[i]);
							else
								code[i]=message[i]+n;
						}
					}
					code[strlen(message)]='\0';
					for(i=0;i<strlen(code);i++)
						message[i]=code[i];
					for(i=0;i<strlen(message);i++)
					{	if(message[i]>=65&&message[i]<=90)
							message[i]=90-(message[i]-65);
						if(message[i]>=97&&message[i]<=122)
							message[i]=122-(message[i]-97);
					}
					for(int x=0,i=0;x<strlen(message);x++)
					{	if(isalpha(message[x]))
						{       int a=toupper(message[x])-64;
							if(toupper(message[x])<'J')
							{	code[i]=a+48;
								i++;
							}
							else
							{	int n=a/10;
								n+=48;
								code[i]=n;
								i++;
								n=a%10;
								n+=48;
								code[i]=n;
								i++;
							}
							if(isalpha(message[x+1]))
							{	code[i]='-';
								i++;
							}
						}
						else
						{	code[i]=message[x];
							i++;
						}
					}
					code[i]='\0';
					cout<<"\n The combined code is: \n"<<code<<endl;
					filestore(code);
					break;
				}
				else if(strcmp(choice,"decrypt")==0)
				{	cout<<"\n Enter the code \n";
					gets(code);
					int b,c,d,e;
					char g;
					b=0;e=0;
					while(code[b]!='\0')
					{
						c=0;
						while(code[b]>47 && code[b]<58)
						{
							d=(int) code[b];
							d-=48;
							c=c*10+d;
							b++;
						}
						if(code[b-1]>47 && code[b-1]<58)
						{	g=(char) c+64;
							message[e]=g;
							e++;
						}
						if(code[b]<48 && code[b]!='-' || code[b]>57 && code[b]!='-')
						{	message[e]=code[b];
							e++;
						}
						if(code[b]!='\0')
							++b;
					}
					for(i=0;i<=strlen(message);i++)
						code[i]=message[i];
					for(i=0;i<strlen(code);i++)
					{	if(code[i]>=65&&code[i]<=90)
							code[i]=90-(code[i]-65);
						if(code[i]>=97&&code[i]<=122)
							code[i]=122-(code[i]-97);
					}
					for(i=0;i<strlen(code);i++)
					{       if(code[i]<65 || code[i]>122 || code[i]>90 && code[i]<97)
							message[i]=code[i];
						else if(code[i]>64 && code[i]<91)
						{	if(code[i]-n<65)
								message[i]='Z'-n+(code[i]-64);
							else
								message[i]=code[i]-n;
						}
						else if(code[i]>96 && code[i]<123)
						{	if(code[i]-n<97)
								message[i]='z'-n+(code[i]-96);
							else
								message[i]=code[i]-n;
						}
					}
					message[strlen(code)]='\0';
					cout<<" \n The message hidden in the combined code is: \n"<<message<<endl;
					filestore(message);
					break;
				}
				else
					cout<<"Try again. Enter encrypt or decrypt. \n";
			}
			break;
		}
		else
			cout<<"Try again. Enter a number between 0 and 26. \n";
	}
}
void ciphers::vigenere()
{       char message[77];char code[77];char key[28];char choice[14],ca[77];
	cout<<"\n Encrypt or decrypt? \n";
	for(int p=1;p>0;p++)
	{       gets(choice);
		for(int j=0;j<strlen(choice);j++)
			choice[j]=tolower(choice[j]);
		if(strcmp(choice,"encrypt")==0)
		{	cout<<"\n Enter the message \n";
			gets(message);
			cout<<"key: ";
			gets(key);
			int i=0,s;j=0;
			for(i=0;i<77;i++)
			{
				code[i]='\0';
			}
			i=0;
			for(int x=0;x<strlen(message);x++)
			{
				if(isalpha(message[x]))
				{
					if(isupper(message[x]))
					ca[x]='u';
					else
					ca[x]='l';
				}
				else
				{
				ca[x]='n';
				}
				message[x]=toupper(message[x]);
				key[x]=toupper(key[x]);
			}
			while(j<strlen(message))
			{
				if(isalpha(message[j]))
				{
					s=key[i]-65;
					code[j]=message[j]+s;
					if(code[j]>90)
					{
						code[j]=code[j]-26;
					}
					i++;
				}
				else
				{code[j]=message[j]; }
				j++;
				if(i==strlen(key))
				i=0;
			}

			cout<<"\n The vigenere code is: \n";
			for(x=0;x<strlen(message);x++)
			{
				if(isalpha(code[x]))
				{
					if(ca[x]=='u')
					code[x]=toupper(code[x]);
					else
					code[x]=tolower(code[x]);
				}
				else
				continue;
			}
			puts(code);
			filestore(code);
			break;
		}
		else if(strcmp(choice,"decrypt")==0)
		{	cout<<"\n Enter the code \n";
			gets(code);
			cout<<"key:";
			gets(key);
			int i=0,s;j=0;
			for(i=0;i<77;i++)
			{
				message[i]='\0';
			}
			i=0;
			for(int x=0;x<strlen(code);x++)
			{
				if(isalpha(code[x]))
				{
					if(isupper(code[x]))
					ca[x]='u';
					else
					ca[x]='l';
				}
				else
				{
				ca[x]='n';
				}
				code[x]=toupper(code[x]);
				key[x]=toupper(key[x]);
			}
			while(j<strlen(code))
			{
				if(isalpha(code[j]))
				{
				       s=key[i]-65;
				       message[j]=code[j]-s;
					if(message[j]<65)
					{
						message[j]=message[j]+26;
					}
					i++;
				}
				else
				{message[j]=code[j]; }
				j++;
				if(i==strlen(key))
				i=0;
			}
			cout<<"\n The message hidden in the code is: \n";
			for(x=0;x<strlen(message);x++)
			{
				if(isalpha(code[x]))
				{
					if(ca[x]=='u')
					message[x]=toupper(message[x]);
					else
					message[x]=tolower(message[x]);
				}
				else
				continue;
			}
			puts(message);
			filestore(message);
			break;
		}
		else
			cout<<"\n Try again. Encrypt or decrypt \n";
	}
}
void ciphers::polybius()
{       char choice[14];int r=6;int c=6;char a='\0',b='\0';char message[77]="";char code[154]="";int x,y;int n=0;int p=7,q=7;
	char grid[6][6]={'a','b','c','d','e','f',
			 'g','h','i','j','k','l',
			 'm','n','o','p','q','r',
			 's','t','u','v','w','x',
			 'y','z','0','1','2','3',
			 '4','5','6','7','8','9'};
	for(int i=1;i>0;i++)
	{	cout<<"\n The default 6x6 grid or custom?(default/custom) \n";
		gets(choice);
		for(int j=0;j<strlen(choice);j++)
			choice[j]=tolower(choice[j]);
		if(strcmp(choice,"default")==0)
			break;
		else if(strcmp(choice,"custom")==0)
		{	cout<<"\n Enter the size of the grid, rows and columns. Max is 6. \n";
			cin>>r>>c;
			cout<<"\n Are any 2 characters sharing the same coordinates? \n";
			gets(choice);
			for(j=0;j<strlen(choice);j++)
				choice[j]=tolower(choice[j]);
			for(j=1;j>0;j++)
			{	if(strcmp(choice,"yes")==0)
				{	cout<<"\n Enter the characters \n";
					cin>>a>>b;
					break;
				}
				else if(strcmp(choice,"no")==0)
					break;
				else
				{	cout<<"\n Try again. Enter yes or no \n";
					continue;
				}
			}
			cout<<"\n Enter the characters of the grid(no 2 characters at a time) \n";
			for(j=0;j<r;j++)
			{	for(int k=0;k<c;k++)
				{	cin>>grid[j][k];
					grid[j][k]=tolower(grid[j][k]);
				}
			}
			for(j=0;j<r;j++)
			{	for(int k=0;k<c;k++)
				{	if(grid[j][k]==a)
					{       p=j;
						q=k;
						break;
					}
					else if(grid[j][k]==b)
					{       p=j;
						q=k;
						break;
					}
				}
			}
			break;
		}
		else
		{	cout<<"\n Try again. \n";
			continue;
		}
	}
	for(i=1;i>0;i++)
	{	cout<<"\n Encrypt or decrypt? \n";
		gets(choice);
		for(int j=0;j<strlen(choice);j++)
			choice[j]=tolower(choice[j]);
		if(strcmp(choice,"encrypt")==0)
		{       cout<<"\n Enter the message \n";
			gets(message);
			for(j=0;j<strlen(choice);j++)
				message[j]=tolower(message[j]);
			for(j=0;j<strlen(message);j++)
			{	for(x=0;x<r;x++)
				{	for(y=0;y<c;y++)
					{       if(message[j]==a || message[j]==b)
						{       code[n]=p+65;
							code[n+1]=q+65;
							n+=2;
							goto a;
						}
						else if(message[j]==grid[x][y])
						{       code[n]=x+65;
							code[n+1]=y+65;
							n+=2;
							goto a;
						}
						else if(message[j]<48 || message[j]>57 && message[j]<65 || message[j]>90 && message[j]<97 || message[j]>122)
						{	code[n]=message[j];
							++n;
							goto a;
						}
					}
				}
				a:
			}
			code[strlen(code)]='\0';
			cout<<"\n The polybius code for the message is: \n"<<code<<endl;
			filestore(code);
			break;
		}
		else if(strcmp(choice,"decrypt")==0)
		{       c:
			char  cr=64+r;char cc=64+c;
			cout<<"\n Enter the code... The letters allowed in the code are: \n from A to "<<cr<<" for every 1st letter and from A to "<<cc<<" for the 2nd letter \n";
			gets(code);
			for(j=0;j<strlen(code);j++)
				code[j]=toupper(code[j]);
			for(int p=0;p<strlen(code)-1;p+=2)
			{	for(int q=1;q<strlen(code);q+=2)
				{       if(code[p]==' ')
					{	++p;
						++q;
					}
					if(code[p]>cr || code[q]>cc)
					{	cout<<" There was an invalid letter found in the code. Try again. \n";
						goto c;
					}
				}
			}
			for(j=0;j<strlen(code);j+=2)
			{       b:
				for(x=0;x<r;x++)
				{	for(y=0;y<c;y++)
					{	if(x+65==code[j] && y+65==code[j+1])
						{	message[n]=grid[x][y];
							++n;
							break;
						}
						else if(code[j]<48 || code[j]>57 && code[j]<65 || code[j]>70 && code[j]<97 || code[j]>122)
						{	message[n]=code[j];
							++n;
							++j;
							goto b;
						}
					}
				}
			}
			message[strlen(message)]=0;
			cout<<"\n The message hidden in the polybius code is: \n"<<message<<endl;
			filestore(message);
			break;
		}
		else
			cout<<"\n Try again. Enter encrypt or decrypt. \n";
	}
}
void ciphers::binary()
{	char message[77];char code[7777];char choice[14];int code1[777];
	for(int j=1;j>0;j++)
	{	cout<<"\n Encrypt or decrypt? \n";
		gets(choice);
		for(int i=0;i<strlen(choice);i++)
			choice[i]=tolower(choice[i]);
		if(strcmp(choice,"encrypt")==0)
		{       int x=0;
			cout<<"\n Enter the message \n";
			gets(message);
			for(i=0;i<strlen(message);i++)
			{	int c=7;int a[8];
				int n=message[i];
				for(int k=2;k<512;k*=2)
				{       for(int l=0;l<k/2;l++)
					{	if((n-l)%k==0)
						{	a[c]=0;
							break;
						}
						else
							a[c]=1;
					}
					c--;
				}
				for(int z=0;z<8;z++,x++)
					code1[x]=a[z];
			}
			cout<<"\n The binary code for the message is: \n";
			for(int k=0;k<8*strlen(message);k++)
				code[k]=code1[k]+48;
			code[strlen(message)*8]='\0';
			cout<<code<<endl;
			filestore(code);
			break;
		}
		else if(strcmp(choice,"decrypt")==0)
		{       c:
			cout<<"\n Enter the code \n";
			gets(code);
			int n=0;int l=0;int a;char one[8];
			for(int x=0;x<strlen(code);x+=8)
			{       for(int z=0;z<8;z++)
					one[z]=code[z+x];
				n=0;
				for(int k=0,i=7;i>=0;i--,k++)
				{       if(one[i]!='1' && one[i]!='0')
					{	cout<<"\n Something went wrong. Try again. \n";
						goto c;
					}
					a=one[i]-48;
					n+=a*pow(2,k);
				}
				message[l]=n;
				l++;
			}
			message[strlen(code)/8]='\0';
			cout<<"\n The message hidden in the binary code is: \n";
			puts(message);
			filestore(message);
			break;
		}
		else
		{	cout<<" Try again. Enter encrypt or decrypt \n";
			continue;
		}
	}
}
void intro()
{	clrscr();
	cout<<" \n\n\n\n                                  INTRODUCTION \n \n";
	cout<<" Messaging apps, bank transactions, airline communications, army, weather \n";
	cout<<" reports, etc., all use coding and decoding. Coding has been around for \n";
	cout<<" millenia but only recently has it become so complex that the same letter \n";
	cout<<" can have different encryptions, like vigenere in this project. Ciphers like \n";
	cout<<" this have been used very often in wars incuding the civil war and the \n";
	cout<<" world wars.\n This project was inspired by a cartoon called GravityFalls and the ciphers \n";
	cout<<" in this project are all present in the cartoon. That's why this program is \n";
	cout<<" THE GRAVITY ENCRYPTER. There are 7 ciphers in this project. \n Press a key to continue... \n";
	getch();
	int counter=1;
	a:
	clrscr();
	char c;
	cout<<" Use the W and S keys to select the name of the ciphers if you don't know  how \n";
	cout<<" to use them and want to be introduced to them or select \"MENU\" to get to the \n";
	cout<<" menu if you know about them. Press \"ESCAPE\" to exit. Checking the introduction ";
	cout<<" of the ciphers first is recommended. \n";
	if(counter==1)
		textcolor(2);
	else
		textcolor(7);
	cprintf("\n ->Caesar \r\n");
	++counter;
	if(counter==1)
		textcolor(2);
	else
		textcolor(7);
	cprintf(" ->Atbash \r\n");
	++counter;
	if(counter==1)
		textcolor(2);
	else
		textcolor(7);
	cprintf(" ->A1Z26 \r\n");
	++counter;
	if(counter==1)
		textcolor(2);
	else
		textcolor(7);
	cprintf(" ->Combined \r\n");
	++counter;
	if(counter==1)
		textcolor(2);
	else
		textcolor(7);
	cprintf(" ->Vigenere \r\n");
	++counter;
	if(counter==1)
		textcolor(2);
	else
		textcolor(7);
	cprintf(" ->Polybius \r\n");
	++counter;
	if(counter==1)
		textcolor(2);
	else
		textcolor(7);
	cprintf(" ->Binary \r\n");
	++counter;
	if(counter==1)
		textcolor(3);
	else
		textcolor(7);
	cprintf(" ->MENU \r\n");
	c=getch();
	if(c==27)
	{       clrscr();
		cout<<"\n \n \n \n \n \n                                C R E D I T S \n \n \n                              Abijit Gupta(12 B) \n \n                             Aseer Uz Zaman(12 B) \n \n \n";
		cout<<"\n      	          Thank you for using THE GRAVITY ENCRYPTER \n";
		getch();
		exit(0);
	}
	else if(c=='w' && counter!=8 || c=='W' && counter!=8)
		counter-=6;
	else if(c=='s' && counter!=1 || c=='S' && counter!=1)
		counter-=8;
	else if(c==13)
	{	int numb=9-counter;
		if(numb==1)
		{	clrscr();
			cout<<" \n\n\n\n Caesar-This is one of the simplest ciphers. This cipher first takes a number \n";
			cout<<" from 0 to 26 and replaces every letter in the message by a letter the given \n";
			cout<<" number ahead of it. It does this during encryption. For decryption, every \n";
			cout<<" letter in the entered cipher is replaced by the letter the given number \n";
			cout<<" behind it, deciphering the cipher. Example... \n";
			cout<<" If the number entered is 3 and the message is \"ABCWXYZ\" the the cipher will be ";
			cout<<" \"DEFZABC\" and for decrypting, \"DEFZABC\" is converted to \"ABCWXYZ\" if the \n";
			cout<<" number is still 3. So, for decrypting, you must know the number used to create\n";
			cout<<" the cipher, or you can try 26 times with a number everytime until the output \n";
			cout<<" looks like a sensible message. \n";
			cout<<" Press any key to continue...";
		}
		else if(numb==2)
		{       clrscr();
			cout<<" \n\n\n\n Atbash-This is a simple code. The alphabet has 26 letters with M and N \n";
			cout<<" in the middle. This cipher changes a letter to its mirror letter about \n";
			cout<<" the central axis. Z changes to A at the ends and M changes to N in the \n";
			cout<<" middle. B and Y are connected the same way and C and X are connected the \n";
			cout<<" same way. It doesn't have encryption and decryption seperately as they \n";
			cout<<" both involve the same process and if a message is subjected to this twice, \n";
			cout<<" it returns to its original form. Numbers and other characters are unaltered. \n";
			cout<<" Press any key to go back...";
		}
		else if(numb==3)
		{       clrscr();
			cout<<" \n\n\n\n\n A1Z26-As the name of this cipher tells, it converts letters to their \n";
			cout<<" corresponding numbers in the alphabet. It changes A to 1, B to 2,..., Z to 26.\n";
			cout<<" In a word, the numbers are seperated by hiphens(-) to clearly see if the \n";
			cout<<" 2-digit numbers represent 1 single letter or 2 different letters. While \n";
			cout<<" encryption, the numbers and other characters are unaltered and while \n";
			cout<<" decryption, any letters used are unaltered. The code must be entered in the \n";
			cout<<" format displayed. The numbers are seperated by hiphens and the usual space \n";
			cout<<" between the words. \n";
			cout<<" Press any key to go back...";
		}
		else if(numb==4)
		{       clrscr();
			cout<<" \n\n\n\n\n Combined-This cipher is the one created by combining Casaer, Atbash and A1Z26.\n";
			cout<<" It asks for the number the it uses for caesar and then applies atbash to that \n";
			cout<<" caesar code. Then, it is changed to its A1Z26 equivalent which is the result. \n";
			cout<<" Example, if the number entered is 3 and the message is \"ABCWXYZ\", it changes \n";
			cout<<" to \"DEFZABC\", then to \"WVUAZYX\" and finally to \"23-22-21-1-26-25-24\". \n";
			cout<<" This code looks just like A1Z26 with numbers seperated by hiphens in a word \n";
			cout<<" and words seperated by spaces. This is also the format in which the code \n";
			cout<<" should be entered while decryption. \n";
			cout<<" Press any key to go back...";
		}
		else if(numb==5)
		{       clrscr();
			cout<<" \n\n Vigenere-This is the toughest cipher in this project since the same letter \n";
			cout<<" can have different encryptions based on what the key is. It uses a grid \n";
			cout<<" called the Vigenere grid. This grid is too big to display here. \n";
			cout<<" The way this cipher is used is first the letters of the key are repeated to \n";
			cout<<" match the number of letters in the message. Then, the first letter of the \n";
			cout<<" message and that of the key are used as the coordinates in the grid and the \n";
			cout<<" letter that they point to is the first letter of the cipher. This continues \n";
			cout<<" until the length of the message is reached. \n";
			cout<<" If the message is \"Thirty Degrees East\" and the key entered is \"Gravity\", \n";
			cout<<" then the key is repeated until it's the same length as the message. So, here \n";
			cout<<" it's \"GRAVITYGRAVITYGRA\" so that both, the message and the key are now \n";
			cout<<" having 17 characters excluding the 2 spaces in the message, so we have 17 \n";
			cout<<" coordinates that will give us 17 letters as our code, excluding the 2 spaces \n";
			cout<<" that it will also have in the right places. So the code trns out to be \n";
			cout<<" \"ZYIMBR BKXRZML CGJT\". You can see the same letter can have different \n";
			cout<<" encryptions depending on the key and the length of the message before the \n";
			cout<<" letter. \n";
			cout<<" For decrypting, the code letter is found in the grid and the key as one\n";
			cout<<" of the coordinates, then the other coordinate is a letter from the message. \n";
			cout<<" Ofcourse you need to know the key if you have a code that you want to decipher.";
			cout<<" Press any key to go back...";
		}
		else if(numb==6)
		{       clrscr();
			cout<<" \n Polybius-This cipher is also based on a grid just like Vigenere. But in this \n";
			cout<<" cipher, the code has almost double the length than that of the message. The \n";
			cout<<" default 6x6 grid that has 36 characters is shown below... \n";
			cout<<"  | A  B  C  D  E  F \n";
			cout<<" --------------------\n";
			cout<<" A| A  B  C  D  E  F \n";
			cout<<" B| G  H  I  J  K  L \n";
			cout<<" C| M  N  O  P  Q  R \n";
			cout<<" D| S  T  U  V  W  X \n";
			cout<<" E| Y  Z  0  1  2  3 \n";
			cout<<" F| 4  5  6  7  8  9 \n\n";
			cout<<" This grid has the 26 letters plus the 10 digits, so this grid encrypts all the\n";
			cout<<" letters and the digits. Other characters including spaces are unaltered. \n";
			cout<<" The way this works is every letter in the message is changed to its coordinates";
			cout<<" which are the first 6 letters. So, A becomes AA, B becomes AB, G becomes BA, Q\n";
			cout<<" becomes CE, 0 becomes EC, 7 becomes FD, and so on. So, the letters in the code ";
			cout<<" can only be from A to F and there may be some special characters. \n";
			cout<<" Many times, a 5x5 grid is used that has 25 letters and one place is shared by \n";
			cout<<" two letters that sound the same, example C and K or G and J. When a message is\n";
			cout<<" coded using this grid, the letters that share the place have same coordinates.\n";
			cout<<" This kind of a grid can be made by selecting the CUSTOM option. \n";
			cout<<" Press any key to go back...";
		}
		else if(numb==7)
		{       clrscr();
			cout<<" \n\n\n\n\n Binary-This cipher is probably known to you. A message is entered and every \n";
			cout<<" character of the message is converted to its ASCII value and then to its \n";
			cout<<" binary equivalent. The reverse process is done for decryption. \n";
			cout<<" For example, A is coverted to 65, its ASCII value, and 65 is converted to \n";
			cout<<" 01000001, its binary value. For every character in the message, there's an \n";
			cout<<" 8-digit combination of 0s and 1s. So, the lenght of the code is 8 times that \n";
			cout<<" of the message. All the 256 letters of the ASCII are present in this program. \n";
			cout<<" Press any key to go back...";

		}
		else if(numb==8)
		{       clrscr();
			goto b;
		}
		getch();
		counter=1;
	}
	else
		counter-=7;
	goto a;
	b:
}
void main()
{	clrscr();
	cout<<"\n \n \n \n \n \n \n		           W E L C O M E    T O \n \n \n                   T H E  G R A V I T Y  E N C R Y P T E R \n \n              A program used to encrypt and decrypt information \n \n \n";
	delay(2222);
	cout<<"\n Press any key to continue... \n";
	getche();
	clrscr();
	intro();
	for(int i=1;i>0;i++)
	{       int counter=1;ciphers o;
		tag:
		clrscr();
		char c;
		cout<<" Choose an option. Use the W ans S keys and press ESCAPE to exit: \n";
		if(counter==1)
			textcolor(2);
		else
			textcolor(7);
		cprintf(" ->Caesar \r\n");
		++counter;
		if(counter==1)
			textcolor(2);
		else
			textcolor(7);
		cprintf(" ->Atbash \r\n");
		++counter;
		if(counter==1)
			textcolor(2);
		else
			textcolor(7);
		cprintf(" ->A1Z26 \r\n");
		++counter;
		if(counter==1)
			textcolor(2);
		else
			textcolor(7);
		cprintf(" ->Combined \r\n");
		++counter;
		if(counter==1)
			textcolor(2);
		else
			textcolor(7);
		cprintf(" ->Vigenere \r\n");
		++counter;
		if(counter==1)
			textcolor(2);
		else
			textcolor(7);
		cprintf(" ->Polybius \r\n");
		++counter;
		if(counter==1)
			textcolor(2);
		else
			textcolor(7);
		cprintf(" ->Binary \r\n");
		++counter;
		if(counter==1)
			textcolor(3);
		else
			textcolor(7);
		cprintf(" ->INTRODUCTION \r\n");
		++counter;
		if(counter==1)
			textcolor(3);
		else
			textcolor(7);
		cprintf(" ->OPEN A FILE \r\n");
		c=getch();
		if(c==27)
		{       clrscr();
			cout<<"\n \n \n \n \n \n                                C R E D I T S \n \n \n                              Abijit Gupta(12 B) \n \n                             Aseer Uz Zaman(12 B) \n \n \n";
			cout<<"\n                   Thank you for using THE GRAVITY ENCRYPTER \n";
			getch();
			exit(0);
		}
		else if(c=='w' && counter!=9 || c=='W' && counter!=9)
			counter-=7;
		else if(c=='s' && counter!=1 || c=='S' && counter!=1)
			counter-=9;
		else if(c==13)
		{	int n=10-counter;
			if(n==1)
				o.caesar();
			else if(n==2)
				o.atbash();
			else if(n==3)
				o.a1z26();
			else if(n==4)
				o.combined();
			else if(n==5)
				o.vigenere();
			else if(n==6)
				o.polybius();
			else if(n==7)
				o.binary();
			else if(n==8)
				intro();
			else if(n==9)
			{       cout<<"\n Enter the file name \n";
				char fname[77];
				gets(fname);
				ifstream fin(fname);
				if(!fin)
					cout<<"\n No file exists by this name. \n";
				else
				{	char ch;
					cout<<"Contents of the file are: \n";
					while(!fin.eof())
					{	fin.get(ch);
						cout<<ch;
					}
					cout<<endl;
					fin.close();
				}
			}
			getch();
			counter=1;
		}
		else
			counter-=8;
		goto tag;
	}
}