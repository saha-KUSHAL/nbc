#include "system.h"

//function to add personal details of student
void add_std_per_data(/*add parameters*/){
	std_per_data *data = (std_per_data *)malloc(sizeof(std_per_data)); //allocating memeory
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
	//how to store data? need a key
	free(data);
}

//function to add educational details
void add_std_edu_data(/*add parameters*/){
	std_edu_data * data=(std_edu_data *)malloc(sizeof(std_edu_data));
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
	free(data);
}