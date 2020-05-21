#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static char* revstring(char* intal)
{
    char temp;
    int i=strlen(intal);
    for(int j=0; j<i/2; j++)
    {
        temp=intal[j];
        intal[j]=intal[i-1-j];
        intal[i-1-j]=temp;
    }
    return intal;
}

static int magic(const char* p,int i)
{
    if(i<strlen(p))
    {
        return p[strlen(p)-i-1]-'0';
    }
    return 0;
}

char* intal_add(const char* intal1, const char* intal2)
{
    int n1=strlen(intal1);
    int n2=strlen(intal2);
    int p=n1>n2?n1:n2;
    char* temp=(char *)malloc((p+2)*sizeof(char));
    int i=n1-1;
    int j=n2-1;
    int k=0;    
    int sum,c=0;
    while(i>=0 && j>=0 && k<p+2)
    {
        sum=(intal1[i]-'0')+(intal2[j]-'0')+c;
        c=sum/10;
        sum=sum%10;
        temp[k]=sum+'0';
        i--;j--;k++;
    }
    while(i>=0 && k<p+2)
    {
        sum=(intal1[i]-'0')+c;
        c=sum/10;
        sum=sum%10;
        temp[k]=sum+'0';
        i--;k++;
    }
    while(j>=0 && k<p+2)
    {
        sum=(intal2[j]-'0')+c;
        c=sum/10;
        sum=sum%10;
        temp[k]=sum+'0';
        j--;k++;
    }
    if(n1>n2)
    {
        if(c==0)
            temp[n1]='\0';
        else
        {
            temp[n1]=c+'0';
            temp[n1+1]='\0';
        }
    }
    else
    {
        if(c==0)
            temp[n2]='\0';
        else
        {
            temp[n2]=c+'0';
            temp[n2+1]='\0';
        }
    }
    return revstring(temp);
}

int intal_compare(const char* intal1, const char* intal2)
{
    int i=0;
    if(strlen(intal1)>strlen(intal2))
        return 1;
    if(strlen(intal1)<strlen(intal2))
        return -1;
    else
    {
        while(i<strlen(intal1))
        {
                if(intal1[i]>intal2[i])
                    return 1;
                if(intal1[i]<intal2[i])
                    return -1;
                else
                {   i++;  }
        }
        return 0;
    }
}

char* intal_diff(const char* intal1, const char* intal2)
{
    int n1=strlen(intal1);
    int n2=strlen(intal2);
    //char* rn1=strrev(intal1);
    //char* rn2=strrev(intal2);
    int p=n1>n2?n1:n2;
    char* temp=(char *)malloc((p+2)*sizeof(char));
    int i=n1-1;
    int j=n2-1;
    int k=0;    
    int sub,c=0;
    if(p==n1)
    {
        while(i>=0 && j>=0 && k<p+1)
        {
            sub=(intal1[i]-'0')-(intal2[j]-'0')-c;
            if(sub<0)
            {
                sub=sub+10;
                c=1;
            }
            else
                c=0;
            temp[k]=sub+'0';
            i--;j--;k++;
        }
        while(i>=0 && k<p+1) 
        {
            sub=(intal1[i]-'0')-c;
            if(sub<0)
            {
                sub=sub+10;
                c=1;
            }
            else
                c=0;
            temp[k]=sub+'0';
            i--;k++;
        }
        int i=n1-1;
        while(i>0)
        {
            if(temp[i]=='0')
            {    
                temp[i]='\0';                
                i--;
            }
            else
                break;   
        }          
        return revstring(temp);
    }
    else
    {   
        while(j>=0 && i>=0 && k<p+1)
        {
            sub=(intal2[j]-'0')-(intal1[i]-'0')-c;
            if(sub<0)
            {
                sub=sub+10;
                c=1;
            }
            else
                c=0;
            temp[k]=sub+'0';
            i--;j--;k++;
        }
        while(j>=0 && k<p+1) 
        {
            sub=(intal2[j]-'0')-c;
            if(sub<0)
            {
                sub=sub+10;
                c=1;
            }
            else
                c=0;
            temp[k]=sub+'0';
            j--;k++;
        }
        int i=n2-1;
        while(i>0)
        {
            if(temp[i]=='0')
            {    
                temp[i]='\0';                
                i--;
            }
            else
                break;   
        }             
        return revstring(temp);
    }
}

/*char* intal_multiply(const char* intal1, const char* intal2)
{
    int l1=strlen(intal1);
    int l2=strlen(intal2);
    char* result=(char *)malloc((l1*l2+1)*sizeof(char));
    int* temp=(int *)malloc((l1*l2+1)*sizeof(int));
    if(l1==0 || l2==0)
    {
        strcpy(result,"0");
        return result;
    }
    int p1=0;
    int p2=0;
    for(int i=l1-1;i>=0;i--)
    {
        int c=0;
        int n1=intal1[i]-'0';
        p2=0;
        for(int j=l2-1;j>=0;j--)
        {
            int n2=intal2[j]-'0';
            int sum=n1*n2+temp[p1+p2]+c;
            c=sum/10;
            temp[p1+p2]=sum%10;
            p2++;
        }
        if(c>0)
            temp[p1+p2] +=c;
        p1++;
    }
    for(int i=0;i<(l1+l2+2);i++)
        result[i]=temp[i]+'0';
    free(temp);
    int i=strlen(result)-1;
    while(i>=0 && result[i]=='0')
    {
        if(result[i]=='0')
        {
            result[i]='\0';
            i--;
        }
        else
            break;
    }
    if(i==-1)
        strcpy(result,"0");
    return revstring(result);
}*/

char* intal_multiply(const char* intal1, const char* intal2)
{
    if(strcmp(intal1,"0")==0 || strcmp(intal2,"0")==0)
    {
        char* result=malloc(2*sizeof(char));
        result[0]='0';
        result[1]=0;
        return result;
    }
    int n1=strlen(intal1);
    int n2=strlen(intal2);
    char* temp=malloc((n1*n2+1)*sizeof(char));
    //char* d;
    int mul,a,b,k;
    int c=0;
    char* result="0";
    for(int i=0;i<strlen(intal1);i++)
    {
        k=0;
        c=0;
        a=magic(intal1,i);
        for(;k<i;k++)
            temp[k]='0';
        for(int j=0;j<strlen(intal2);j++)
        {
            b=magic(intal2,j);
            mul=(a*b)+c;
            c=mul/10;
            mul=mul%10;
            temp[k++]=mul+'0';
        }
        if(c)
            temp[k++]=c+'0';
        temp[k]=0;
        result=intal_add(result,revstring(temp));
    }
    free(temp);
    return result;
}

char* intal_pow(const char* intal1, unsigned int n)
{
    const char* temp;
    const char* temp1;
    char* ans=malloc(2*sizeof(char));
    if(*(intal1)=='\0')
    {
        strcpy(ans,"0");
        return ans;
    }
    if(n==0)
    {
        strcpy(ans,"1");
        return ans;
    }
    temp= intal_pow(intal1,n/2);
    if(n%2==0)
        return intal_multiply(temp,temp);
    else
    {
        temp1=intal_multiply(temp,temp);
        return intal_multiply(intal1,temp1);
    }
    free(ans);
}

char* intal_mod(const char* intal1, const char* intal2)
{
    //int n1=strlen(intal1);
    //int n2=strlen(intal2);
    //int a=n1>n2?n1:n2;
    int i=strlen(intal1)-1;
    int p,q;
    char* pow;
    char* check;
    const char* temp=intal1;
    while(i>=0)
    {
        pow=intal_pow("10",i);
        check=intal_multiply(intal2,pow);
        p=intal_compare(check,temp);
        if(p==1)
            i--;
        else
        {
            q=intal_compare(temp,check);
            while(q!=-1)
            {
                temp=intal_diff(temp,check);
                q=intal_compare(temp,check);
            }           

        }
    }
    char* r=malloc((strlen(temp)+1)*sizeof(char));
    strcpy(r,temp);
    return r;       
}

char* intal_gcd(const char* intal1, const char* intal2)
{
    char* p;
   // const char* q;
    int x=intal_compare(intal1,"0");
    int y=intal_compare(intal2,"0");
    int n2=strlen(intal2);
    char* b=(char *)malloc((n2+1)*(sizeof(char)));
    strcpy(b,intal2);
    char* ans=malloc(2*sizeof(char));
    if(x==0 && y==0)
    {
        strcpy(ans,"0");
        return ans;
    }
    if(x==0)
        return b;
    else
    {
        //printf("%s   %s\n",intal1,intal2);
        p=intal_mod(intal2,intal1);
       // printf("%s\n",p);
        //q=intal1;
        //intal1=p;
        //free(q);
        return intal_gcd(p,intal1);
    }
    free(ans);
}

char* intal_fibonacci(unsigned int n)
{
    char** f=(char **)malloc((n+2)*sizeof(char));
    f[0]="0";
    f[1]="1";
    for(int i=2;i<=n;i++)
        f[i]=intal_add(f[i-1],f[i-2]);
    return f[n];
}


char* intal_factorial(unsigned int n)
{
    char* result="1";
    char* temp="1";
    for(int i=2;i<=n;i++)
    {
        temp=intal_add(temp,"1");
        result =intal_multiply(result,temp);
    }
    return result;
}

char* intal_bincoeff(unsigned int n, unsigned int k)
{
    int j;
    char** bincof=(char **)malloc(n*sizeof(char*));
    for(int i=1;i<=k;i++)
        bincof[i]="0";
    bincof[0]="1";
    for(int i=1;i<=n;i++)
    {
        j=i<k?i:k;
        for(; j>0 ;j--)
        {    
            bincof[j]=intal_add(bincof[j],bincof[j-1]);
        }
    }
    char* result=malloc((strlen(bincof[k])+1)*sizeof(char));
    strcpy(result,bincof[k]);
    free(bincof);
    return result;
}

int intal_max(char **arr, int n)
{
    int max_indx=0;
    for(int i=1;i<n;i++)
    {
        int p=intal_compare(arr[max_indx],arr[i]);
        if(p==-1)
        {
            max_indx=i;
        }
    }
    return max_indx;
}

int intal_min(char **arr, int n)
{
    int min_indx=0;
    for(int i=1;i<n;i++)
    {
        int p=intal_compare(arr[min_indx],arr[i]);
        if(p!=-1)
        {
            min_indx=i;
        }
    }
    return min_indx;
}


int intal_search(char **arr, int n, const char* key)
{
    for(int i=0;i<n;i++)
    {
        int p=intal_compare(key,arr[i]);
        if(p==0)
        {
            return i;
        }
    }
    return -1;
}


int intal_binsearch(char **arr, int n, const char* key)
{
    int mid,p;
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        mid=(start+end)/2;
        p=intal_compare(arr[mid],key);
        if(p==0)
            return mid;
        else if(p==1)
            end=mid-1;
        else
            start=mid+1;
    }
    return -1;
}

static void merge(char** arr, int l, int m, int r)
{
    //printf("HI3\n");
    int n1=m-l+1;
    int n2=r-m;
    char** templ=(char **)malloc((m-l)*sizeof(char*));
    char** tempr=(char **)malloc((r-m+1)*sizeof(char*));   
    for(int i=0;i<n1;i++)
        templ[i]=arr[l+i];
    for(int j=0;j<n2;j++)
        tempr[j]=arr[m+1+j];
    int i=0;
    int j=0;
    int k=l;
    while(i<n1 && j<n2)
    {
        int p=intal_compare(templ[i],tempr[j]);
        if(p==-1 || p==0)
        {
            arr[k]=templ[i];
            i++;
        }
        else
        {
            arr[k]=tempr[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=templ[i];
        k++;i++;
    }
    while(j<n2)
    {
        arr[k]=tempr[j];
        k++;j++;
    }
free(templ);
free(tempr);
}

static void mergesort(char** arr,int l, int r)
{
    //printf("HI2\n");
    if(l<r)
    {
        int m=l+(r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

void intal_sort(char **arr, int n)
{
   // printf("HI1\n");
    mergesort(arr,0,n-1);
}




char* coin_row_problem(char **arr, int n)
{
    //printf("1\n");
    char* prev;
    char* cur="0";
    char* next;
    int c;
    char* sum;
    if(n==0)
    {
        strcpy(cur,"0");
        return cur;
    }
    prev="0";
    cur=arr[0];
    for(int i=2;i<=n;i++)
    {
        //printf("2\n");
        sum=intal_add(prev,arr[i-1]);
        c=intal_compare(sum,cur);
        if(c==1)
            next=sum;
        else
            next=cur;
        prev=cur;  
        cur=next;
    }
    return cur;
}
