#include "system.h"

int add_std_data(char stream[]){
	FILE *fp;
	std_data * det;
	if(fopen("files/pending.dat","r")==NULL)
		fp=fopen("files/pending.data","w");
	else
		fp=fopen("files/pending.data","w");
	std_per_data *data = (std_per_data *)malloc(sizeof(std_per_data));
	std_edu_data * edu_data=(std_edu_data *)malloc(sizeof(std_edu_data));
	add_std_per_data(data);
	add_std_edu_data(edu_data);
	/* intially planning to write all this data via another structure which
	contains pointer to those two structures*/
	det->data = &data;
	det->edu_data = &edu_data;
	det->sch_data = NULL;
	fwrite(det,sizeof(std_data),1,fp);
	free(data);
	free(edu_data);
	fclose(fp);
	return 1;
}
int add_std_per_data(std_per_data * data){
	green();
	c_printf("--Student Personal Data--");
	reset();
	printf("\nEnter Name:");
	clrbuf();
	fgets(data->name,sizeof(data->name),stdin);
	printf("\nEnter Fathers name:");
	clrbuf();
	fgets(data->f_name,sizeof(data->f_name),stdin);
	printf("\nEnter Mothers Name:");
	clrbuf();
	fgets(data->m_name,sizeof(data->m_name),stdin);
	printf("Date of Birth:");
	clrbuf();
	fgets(data->dob,sizeof(data->dob),stdin);
	printf("\n--Address--");
	printf("\nEnter Village or City:");
	clrbuf();
	fgets(data->address.vill,sizeof(data->address.vill),stdin);	//any other better way to use structute?
	free(data);
	printf("\nPost Office:");
	clrbuf();
	fgets(data->address.po,sizeof(data->address.po),stdin);
	printf("\nPolice Station:");
	clrbuf();
	fgets(data->address.ps,sizeof(data->address.ps),stdin);
	printf("\nDistrict:");
	clrbuf();
	fgets(data->address.dist,sizeof(data->address.dist),stdin);
	printf("\nState:");
	clrbuf();
	fgets(data->address.state,sizeof(data->address.state),stdin);
	printf("\nPin:");
	clrbuf();
	scanf("%d",&data->address.pin);
	printf("\nEnter Adhar No:");
	clrbuf();
	fgets(data->adhar,sizeof(data->adhar),stdin);
	return 1;
}

//function to add educational details
int add_std_edu_data(std_edu_data * data){
	green();
	c_printf("--Educational Details--");
	blue();
	printf("\nHigher Secondary or Equvalant");
	reset();
    printf("\nInstitue Name:");
    clrbuf();
    fgets(data->inst,sizeof(data->inst),stdin);
    printf("\nBoard:");
    clrbuf();
    fgets(data->board,sizeof(data->board),stdin);
    printf("\nPassing date [dd/mm/yyyy]:");
    clrbuf();
    fgets(data->pass_date,sizeof(data->pass_date),stdin);
	printf("\nEnter Total Marks:");
	scanf("%d",&data->marks);
	printf("\nEnter Percentage:");
	clrbuf();
	scanf("%2.2f",&data->persntg);
	return 1;
}
int add_std_schlr_data(std_schlr_data * data){
	c_printf("--Student Scholarship Data--");
	printf("\nEnter Name:");
	clrbuf();
	fgets(data->schlr_name,sizeof(data->schlr_name),stdin);
	printf("\nEnter Authority Name:");
	clrbuf();
	fgets(data->auth,sizeof(data->auth),stdin);
	printf("\nEnter Date in DD/MM/YYY:");
	clrbuf();
	fgets(data->date,sizeof(data->date),stdin);
	return 1;
}