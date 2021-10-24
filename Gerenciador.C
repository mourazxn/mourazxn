#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <stdio_ext.h>
int mes = 0;
int year=21;
int *pontmes = &mes;
char inicio_login;
char inicio_senha;
//declarar arquivo
FILE *file;
//onde guarda nome/compras/agua/luz/transporte...
struct projetinho{
  char name[100];
  float man, p, p1, p2, p3;
  int totel;
  int *ponteiro2;
  float transporte;
  float salary;
  float contas[7][12];
}a; 
struct projetinho totel,*ponteiro2 = &totel;
struct projetinho sla,*v= &sla;
int count;
char meses[100]="JanFevMarAbrMaiJunJulAgoSetOutNovDez";
//executa o codigo principal
int main(){
  void inicio();
  void comida();
  void transportePublico();
  void menuprincipal();
  struct projetinho j1;
  struct projetinho v2;
  printf("Crie seu login:");
  scanf("%s", &inicio_login);
  printf("Crie seu senha:");
  scanf("%s", &inicio_senha);
  printf("Por favor informe seu nome: ");
  file = fopen("extrato.txt", "w");
  while((a.name[count]= fgetc(stdin)) != '\n'){
    count++;
  }
  fprintf(file,"Nome: %s\n",a.name);
  fclose(file);
  return 0;
}
//Primeiro Menu
void menuprincipal(){
  void inicio();
  void comida();
  void transportePublico();
  struct projetinho j1;
  struct projetinho v2;
  count = 0;
  printf("---------------------\n");
  printf("1 - Banco             |\n");
  printf("2 - Geral Na dispensa |\n");
  printf("3 - Condução          |\n");
  scanf("%d",&count);
  count == 1?inicio(a):count==2?comida(j1):count==3?transportePublico(j1):printf("Opção invalida\n"),__fpurge(stdin),menuprincipal();
}
//função de saldo
void saldo(){
  void gerarextrato();
  void checames();
  struct projetinho;
  (*v).transporte = -999999999999;
  (*v).salary  = -999999999999;
  if (a.salary>0){}
  else{
    printf("Nos informe, sobre o seu salario Senhor(a) %s",a.name);
    scanf("%f", &a.salary);
    }
    printf("Vamos a parte triste, as despesas do mês\n");
    if (a.contas[0][mes]>0){}
    else{
      printf("Quanto pagou de transporte?\n");
      scanf("%f", &a.contas[0][mes]);
    }
    printf("Quanto gastou no mercado?\n");
    scanf("%f", &a.contas[1][mes]);
    printf("Quanto paga na luz?\n");
    scanf("%f", &a.contas[2][mes]);
    printf("Quanto paga de agua em sua casa?\n");
    scanf("%f", &a.contas[3][mes]);
    printf("Quanto foi gasto com aluguel?\n");
    scanf("%f", &a.contas[4][mes]);
    printf("Quanto foi gasto com sua faculdade?\n");
    scanf("%f", &a.contas[5][mes]);
    printf("---------------------------------------\n");
    printf("|       Boleto Gerado com Sucesso!    |\n");
    printf("|Esse Mês %.2f com Transporte.\n", a.contas[0][mes]);
    printf("|Esse Mês %.2f com Mercado.\n", a.contas[1][mes]);
    printf("|Esse Mês %.2f com Luz.\n", a.contas[2][mes]);
    printf("|Esse Mês %.2f com Agua.\n", a.contas[3][mes]);
    printf("|Esse Mês %.2f com aluguel.\n", a.contas[4][mes]);
    printf("|Esse Mês %.2f com a faculdade.\n", a.contas[5][mes]);
    printf("|Seu salário foi de %.2f\n", a.salary);
    a.contas[6][mes]= a.salary+a.contas[6][mes-1] - (a.contas[0][mes]+a.contas[1][mes]+a.contas[2][mes]+a.contas[3][mes]+a.contas[4][mes]+a.contas[5][mes]);
    printf("|Seu Saldo atualizado é de %.2f\n", a.contas[6][mes]);
    checames();
    printf("Um arquivo foi gerado com seu extarto do ultimo mês\n");
    file = fopen("extrato.txt", "a");
    fprintf(file,"Saldo: %f\n", a.contas[6][mes]);
    fclose(file);
    if (mes<11){
      *pontmes+=1;
    }
    else{
    pontmes = &year;
    *pontmes+=1;
    pontmes = &mes;
    *pontmes=0;
    }
};
//feature de dividas
void dividas(){
  printf("Nos informe o preço do produto.\n");
    scanf("%f", &a.man);
    printf("Informe o quanto tinha no momento para efetuar esse pagamento.\n");
    scanf("%f", &a.p1);
    float resut = a.man - a.p1;
    printf("O senhor deve %.2f reais a loja/dono do produto.\n", resut);
};
//feature de emprestimo
void emprestimo(){
  printf("De quanto seria o emprestimo? \n");
    scanf("%f", &a.p);
    if(a.p> 20000){
      printf("\npara emprestimo com valores superiores a 20.000 o juros é de 5%%\n");
      printf("Em quantos meses pretende pagar?\n");
      scanf("%f", &a.p1);
      float emptotal;
      emptotal = a.p+(a.p/100)*5;
      emptotal= emptotal/a.p1;    
      printf("O valor mensal será de %.2f", emptotal);
    }
    else{
      printf("Em quantos meses pretende pagar?\n");
      scanf("%f", &a.p1);
      float emptotal;
      emptotal = a.p+(a.p/100)*3.5;
      emptotal= emptotal/a.p1;    
      printf("O valor mensal será de %.2f", emptotal);
    }
};
//feature Bradesco Prime
void Bradesco(){
  printf("Bom dia senhor(a) %s, como você esta hoje?.", a.name);
  printf("Venho aqui para lhe contar a novidade do bradesco premium, nele você terá muitos beneficios como por exemplo:\n");
  printf("Compra de euro e dólar no Auto-Atendimento\n");
  printf("Desconto em ingressos para eventos como cinema e teatro.\n");
  printf("Prime Tv e muito mais!\n");
  printf("Gostaria de se juntar a nós?\n");
  scanf("%f", &a.salary);
  printf("Obrigado pela resposta, aguarde que o retornaremos!");
  };
//feature de contar aumentos
void valorização(){
  float apoio;
  float aumento;
    if (a.salary > 0){}
    else{
      printf("Informe o seu Salario: ");
      scanf("%f", &a.salary);
    }
  printf("Quanto receberá de aumento?\n");
  scanf("%f",&aumento);
  apoio= aumento;
  aumento= (aumento*100)/a.salary;
  printf("O seu aumento será de: %.2f%%",aumento);
  a.salary += apoio;
};
//feature de cotação de dolar
void cotação(){
  float dol, eur;
  printf("Bem vindo a sala internacional do bradesco\n");
  printf("Insira seu dinheiro em reais:\n");
  scanf("%f", &a.p);
  dol = a.p / 5.48;
  eur = a.p / 6.35; 
  printf("O senhor ira receber %.2f doláres\nO Dolar está a 5.48\n", dol);
  printf("O senhor ira receber %.2f euros\nO Euro está a 6.35\n", eur);
  sleep(1);
};
//feature de Pix
void pix(){
  void menu2();
  float fake;
  double nmr;
  printf("|1 Enviar\n|2 Receber\n|3 voltar\n");
  scanf("%d",&count);
  if(count == 1){
    printf("Quanto deseja enviar?\n");
    scanf("%f",&fake);
    (fake>a.contas[6][mes]+a.contas[6][mes-1]) ? printf("Saldo insuficiente\n") ,pix(): 0;
    printf("Digite o Numero ou o cpf da destinatario\n");
    scanf("%lf",&nmr);
    printf("\nR$%.2f enviados para %.0lf ;)", fake,nmr);
    a.contas[6][mes] -= fake;
  }
  else if (count == 2){
    printf("Quanto deseja receber?\n");
    scanf("\n%f",&fake);
    printf("Numero de quem irá te enviar?\n");
    scanf("%lf",&nmr);
    puts("Carregando...");
    sleep(5);
    printf("R$%.2f Recebidos de %.0lf\n",fake,nmr);
    a.contas[6][mes]+=fake;
    pix();
  }
  else if (count == 3){
    menu2(a);
  }
  else{
    printf("Opção invalida\n");
    __fpurge(stdin);
    pix();
  }
};
void gerarextrato(){
  void menu2();
  printf("Deseja imprimir seu extrato?\n|1 Sim\n|2 Não\n");
  scanf("%d",&count);
  if(count == 1){
  }
  else if(count ==2){
    menu2(a);}
  else{printf("invalida");__fpurge(stdin);menu2(a);}
  file = fopen("Extrato.html", "w");
  int mes = 0;
  fprintf(file,"<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n<meta charset=\"UTF-8\">\n<title>Projeto</title>\n<style>\n table{\nborder-style: outset;\nborder-width:medium;\nbackground-color:SteelBlue;\nbox-shadow: 10px 10px 10px 10px black;}\ntr{\nborder-style: groove;}\nth{\nborder-style: groove;}\nbaody{\nbackground-color: Thistle;\n}\n</style></head>\n<body>\n%d\n<table id=\"tablee\">\n<tr>\n",year);
  for(count =0; count<36;count+=3){
    fprintf(file,"<th>%c%c%c</th>\n",meses[count],meses[count+1],meses[count+2]);}
  fprintf(file,"</tr>\n");
  for(count = 0; count<12;count++){
    fprintf(file,"<td bgcolor=\"Aquamarine\">Transpote: %.2f</td>\n", a.contas[0][count]);}
  fprintf(file,"</tr>\n");
  for(count = 0; count<12;count++){
    fprintf(file,"<td bgcolor=\"SpringGreen\">Mercado: %.2f</td>\n", a.contas[1][count]);}
  fprintf(file,"</tr>\n");
  for(count = 0; count<12;count++){
    fprintf(file,"<td bgcolor=\"Yellow\">Energia: %.2f</td>\n", a.contas[2][count]);}
  fprintf(file,"</tr>\n");
  for(count = 0; count<12;count++){
    fprintf(file,"<td bgcolor=\"Gold\">Água: %.2f</td>\n", a.contas[3][count]);}
  fprintf(file,"</tr>\n");
  for(count = 0; count<12;count++){
    fprintf(file,"<td bgcolor=\"CornflowerBlue\">Aluguel: %.2f</td>\n", a.contas[4][count]);}
  fprintf(file,"</tr>\n");
  for(count = 0; count<12;count++){
    fprintf(file,"<td bgcolor=\"RosyBrown\">Faculdade: %.2f</td>\n", a.contas[5][count]);}
  fprintf(file,"</tr>\n");
  for(count = 0; count<12;count++){
    fprintf(file,"<td bgcolor=\"LightCoral\">Saldo: %.2f</td>\n", a.contas[6][count]);}
  fprintf(file,"</tr>\n</table>\n</body>\n</html>");
  fclose(file);
      menu2(a);
}
//Menu inicial
void menu2(struct projetinho a){
  struct projetinho;
  void menuprincipal();
  count=0;
  printf("\n---------------------------------\n");
  printf("Bem-vindo(a)de volta ao Bradesco Senhor(a) %s\n",a.name);
  printf("Como posso lhe ajudar?\n");
  printf("---------------------------------\n"
  "|           |Menu Bradesco|       \n"
  "|1 - Seu Saldo\n"
  "|2 - Suas dividas e pendencias\n"
  "|3 - Faça um empréstimo\n"
  "|4 - Bradesco Premium,venha junto\n"
  "|5 - Valorização\n"
  "|6 - Valor dólar e euro\n"
  "|7 - Pix\n"
  "|8 - Gerar extrato\n"
  "|9 - Voltar\n"
  "-----------------------------------\n");
  scanf("%d", &count);
  count == 1?saldo(),menu2(a):count==2?dividas():count==3?emprestimo(),menu2(a):count==4?Bradesco(),menu2(a):count==5?valorização(),menu2(a):count==6?cotação(),menu2(a):count==7?pix():count ==8?gerarextrato():count==9?menuprincipal():printf("Opção invalida\n"),__fpurge(stdin),menu2(a);
};
//Menu de volta 
void inicio(struct projetinho cad){
  char login;
  char senha;
  struct projetinho;
  count=0;
  printf("Login:");
  scanf("%s", &login);
  printf("Senha:");
  scanf("%s", &senha);
  if(inicio_login ==login&&inicio_senha==senha){
  printf("Seja muito Bem-vindo(a) ao Bradesco Senhor(a) %s\n",a.name);
  printf("Como posso lhe ajudar?\n");
  printf("---------------------------------\n"
  "|           |Menu Bradesco|       \n"
  "|1 - Seu Saldo\n"
  "|2 - Suas dividas e pendencias\n"
  "|3 - Faça um empréstimo\n"
  "|4 - Bradesco Premium,venha junto\n"
  "|5 - Valorização\n"
  "|6 - Valor dólar e euro\n"
  "|7 - Pix\n"
  "|8 - Voltar\n"
  "-----------------------------------\n");
  scanf("%d", &count);
  count == 1?saldo(),menu2(a):count==2?dividas():count==3?emprestimo(),menu2(a):count==4?Bradesco(),menu2(a):count==5?valorização(),menu2(a):count==6?cotação(),menu2(a):count==7?pix():count ==8?menuprincipal():printf("Opção invalida\n"),__fpurge(stdin),inicio(a);}
  else{
    printf("Login Invalido!!");
    inicio(a);
  }
};
//Mercado
void comida(){
  count = 0;
  float feito1, coisa, pp;
  printf("---------------------------------\n|Bem vindo ao Walmart:\n|1 - Pão Francês\n|2 - frios\n|3 - frutas\n|4 - Carne\n|5 - Condimentos\n|6 - Ofertas do Dia\n|7 - Voltar\n---------------------------------\n");
  scanf("%d", &count);
  if (count == 1){
    coisa = 16.90;
    printf("1kg Pão Frances custa 16.90R$\n");
    scanf("%f", &feito1);
    pp = (feito1 - coisa);
    pp < 0 ? printf("Ta pobre em amigo\n"):printf("troco: %.2f\n", pp);
  }
  else if (count == 2){
    coisa = 35.65;
    printf("O 500g de frios é 35.65R$\n");
    scanf("%f", &feito1);
    pp = (feito1 - coisa);
    pp < 0 ? printf("Ta pobre em amigo\n"):printf("troco: %.2f\n", pp); 
  }
  else if (count == 3){
    coisa = 6.50;
    printf("O kilo da Batata custa 6.50R$\n");
    scanf("%f", &feito1);
    pp = (feito1 - coisa);
    pp < 0 ? printf("Ta pobre em amigo\n"):printf("troco: %.2f\n", pp);
  }
  else if (count == 4){
    coisa = 70;
    printf("O kilo da carne custa 70R$\n");
    scanf("%f", &feito1);
    pp = (feito1 - coisa);
    pp < 0 ? printf("Ta pobre em amigo\n"):printf("troco: %.2f\n", pp);
  }
  else if (count == 5){
    coisa = 7;
    printf("Os condimentos custa 7R$\n");
    scanf("%f", &feito1);
    pp = (feito1 - coisa);
    pp < 0 ? printf("Ta pobre em amigo\n"):printf("troco: %.2f\n", pp);
  }
  else if (count == 7){
    menuprincipal();
  }
  else if (count == 6){
    count = 0;
    printf("Qual oferta gostaria de ver? \n|1 Segunda-feira\t|2 Terça-feira\t|3 Quarta-feira\t|4 Quinta-feira|\t|5 Sexta-feira\t|6 Sabado\t|7 Domingo\t\n");
    scanf("%d", &count);
    float res,pp,coisa;
    if (count  == 1){
      coisa = 3;
      printf("O chocolate Biz está 3R$\n");
      scanf("%f", &pp);
      res = pp - coisa;
      0 <= res ? printf("Saldo Restante: %.2f",res): printf("Saldo insuficiente\n");
    }
    else if (count == 2){
      float fr, coca = 5.50;
      printf("Refrigerante Coca-cola 5.50R$\n");
      scanf("%f", &fr);
      float res = fr - coca;
      fr < coca ? printf("Saldo insuficiente\n"):printf("Saldo Restante: %.2f",res);
    } 
    else if (count  == 3){
      coisa = 2;
      printf("Bolacha salgada/doce 2R$\n");
      scanf("%f", &pp);
      res = pp - coisa;
      0 <= res ? printf("Saldo Restante: %.2f",res): printf("Saldo insuficiente\n");
    }
    else if (count  == 4){
      coisa = 7;
      printf("Salgadinho cheetos 7R$\n");
      scanf("%f", &pp);
      res = pp - coisa;
      0 <= res ? printf("Saldo Restante: %.2f",res): printf("Saldo insuficiente\n");
    }
    else if (count  == 5){
      coisa= 2.89;
      printf("Detergente está 2.89R$\n");
      scanf("%f", &pp);
      res = pp - coisa;
      0 <= res ? printf("Saldo Restante: %.2f",res): printf("Saldo insuficiente\n");
    }
    else if (count  == 6){
      coisa = 41.50;
      printf("Amaciante está 13R$\nShaampo clear-men 8.50R$\nCaixa de leite está 20R$\n");
      scanf("%f", &pp);
      res = pp - coisa;
      0 <= res ? printf("Saldo Restante: %.2f",res): printf("Saldo insuficiente\n");
    }
    else if (count  == 7){
      coisa = 10;
      printf("O suco DeValle está 10R$\nFarinha está 6R$\n");
      scanf("%f", &pp);
      res = pp - coisa;
      0 <= res ? printf("Saldo Restante: %.2f",res): printf("Saldo insuficiente\n");
    }
  }
  else{
    printf("Opção invalida\n");
    __fpurge(stdin);
    comida();
  }
  
}
void transportePublico(struct projetinho j1){
  printf("Em qual setor o Senhor(a) %s mora?\n", a.name);
  printf("----------------------------\n1 SP\n2 SBC\n3 SA\n4 SCS\n5 SM\n----------------------------\n");
  scanf("%d",&count);
  if (count == 1 || count == 2 || count == 3 || count == 4 || count == 5){
    printf("E aonde você estuda? %s\n", a.name);
    printf("----------------------------\n1 SP\n2 SBC\n3 SA\n4 SCS\n5 SM\n----------------------------\n");
    scanf("%d", &count);
    printf("E aonde você trabalha? %s\n", a.name);
    printf("----------------------------\n1 SP\n2 SBC\n3 SA\n4 SCS\n5 SM\n----------------------------\n");
    scanf("%d",&count);
    printf("Como você vai de sua casa para seu serviço?\n");
    printf("----------------------------\n1 Metro\n2 Carro\n3 Bike\n4 Andando\n5 Uber\n----------------------------\n");
    float ex, ex2;
    scanf("%d",&count);
    if (count == 1){
      ex = 4.40;
    }
    else if(count == 2){
      ex = 9.98;
    }
    else if(count == 3){
      ex = 0;
    }
    else if (count == 4){
      ex = 0;
    }
    else if (count == 5){
      ex = 10;
    }
    printf("Como você vai do seu serviço á sua faculdade?\n");
    printf("----------------------------\n1 Metro\n2 Carro\n3 Bike\n4 Andando\n5 Uber\n----------------------------\n");
    scanf("%d",&count);
    if (count == 1){
      ex2 = 4.40;
      ex=ex+ex2;
    }
    else if(count == 2){
      ex2 = 9.98;
      ex=ex+ex2;
    }
    else if(count == 3){
      ex2 = 0;
      ex=ex+ex2;
    }
    else if (count == 4){
      ex2 = 0;
      ex=ex+ex2;
    }
    else if (count == 5){
      ex2 = 10;
      ex=ex+ex2;
    }
    printf("Como você vai da sua faculdade á sua Residencia?\n");
    printf("----------------------------\n1 Metro\n2 Carro\n3 Bike\n4 Andando\n5 Uber\n----------------------------\n");
    scanf("%d",&count);
    if (count == 1){
      ex2 = 4.40;
      ex=ex+ex2;
    }
    else if(count == 2){
      ex2 = 9.98;
      ex=ex+ex2;
    }
    else if(count == 3){
      ex2 = 0;
      ex=ex+ex2;
    }
    else if (count == 4){
      ex2 = 0;
      ex=ex+ex2;
    }
    else if (count == 5){
      ex2 = 10;
      ex=ex+ex2;
    }
    a.transporte = ex;
  printf("%s você gastou %.2f no transfer hoje\n", a.name, ex);
  }
  menuprincipal();
}
void checames(mes){
  void saldo();
  if(mes == 0){
    file = fopen("extrato.txt", "a");
    fprintf(file,"Janeiro de %d\nSalario: %f\nTransporte: %f\nMercado: %f\nLuz: %f\nÁgua: %f\nAluguel: %f\nFaculdade: %f\nSaldo: %f\n",year,a.salary,a.contas[0][mes],a.contas[1][mes],a.contas[2][mes],a.contas[3][mes],a.contas[4][mes],a.contas[5][mes],a.contas[6][mes]);
    fclose(file);
  }
  else if(mes == 1){
    file = fopen("extrato.txt", "a");
    fprintf(file,"Fevereiro de %d\nSalario: %f\nTranslado: %f\nCompras: %f\nLuz: %f\nÁgua: %f\nAluguel: %f\nFaculdade: %f\nSaldo: %f\n",year,a.salary,a.contas[0][mes],a.contas[1][mes],a.contas[2][mes],a.contas[3][mes],a.contas[4][mes],a.contas[5][mes],a.contas[6][mes]);
    fclose(file);
  }
  else if(mes == 2){
    file = fopen("extrato.txt", "a");
    fprintf(file,"Março de %d\nSalario: %f\nTranslado: %f\nCompras: %f\nLuz: %f\nÁgua: %f\nAluguel: %f\nFaculdade: %f\nSaldo: %f\n",year,a.salary,a.contas[0][mes],a.contas[1][mes],a.contas[2][mes],a.contas[3][mes],a.contas[4][mes],a.contas[5][mes],a.contas[6][mes]);
    fclose(file);
  }
  else if(mes == 3){
    file = fopen("extrato.txt", "a");
    fprintf(file,"Abril de %d\nSalario: %f\nTranslado: %f\nCompras: %f\nLuz: %f\nÁgua: %f\nAluguel: %f\nFaculdade: %f\nSaldo: %f\n",year,a.salary,a.contas[0][mes],a.contas[1][mes],a.contas[2][mes],a.contas[3][mes],a.contas[4][mes],a.contas[5][mes],a.contas[6][mes]);
    fclose(file);
  }
  else if(mes == 4){
    file = fopen("extrato.txt", "a");
    fprintf(file,"Maio de %d\nSalario: %f\nTranslado: %f\nCompras: %f\nLuz: %f\nÁgua: %f\nAluguel: %f\nFaculdade: %f\nSaldo: %f\n",year,a.salary,a.contas[0][mes],a.contas[1][mes],a.contas[2][mes],a.contas[3][mes],a.contas[4][mes],a.contas[5][mes],a.contas[6][mes]);
    fclose(file);
  }
  else if(mes == 5){
    file = fopen("extrato.txt", "a");
    fprintf(file,"Junho de %d\nSalario: %f\nTranslado: %f\nCompras: %f\nLuz: %f\nÁgua: %f\nAluguel: %f\nFaculdade: %f\nSaldo: %f\n",year,a.salary,a.contas[0][mes],a.contas[1][mes],a.contas[2][mes],a.contas[3][mes],a.contas[4][mes],a.contas[5][mes],a.contas[6][mes]);;
    fclose(file);
  }
  else if(mes == 6){
    file = fopen("extrato.txt", "a");
    fprintf(file,"Julho de %d\nSalario: %f\nTranslado: %f\nCompras: %f\nLuz: %f\nÁgua: %f\nAluguel: %f\nFaculdade: %f\nSaldo: %f\n",year,a.salary,a.contas[0][mes],a.contas[1][mes],a.contas[2][mes],a.contas[3][mes],a.contas[4][mes],a.contas[5][mes],a.contas[6][mes]);
    fclose(file);
  }
  else if(mes == 7){
    file = fopen("extrato.txt", "a");
    fprintf(file,"Agosto de %d\nSalario: %f\nTranslado: %f\nCompras: %f\nLuz: %f\nÁgua: %f\nAluguel: %f\nFaculdade: %f\nSaldo: %f\n",year,a.salary,a.contas[0][mes],a.contas[1][mes],a.contas[2][mes],a.contas[3][mes],a.contas[4][mes],a.contas[5][mes],a.contas[6][mes]);
    fclose(file);
  }
  else if(mes == 8){
    file = fopen("extrato.txt", "a");
    fprintf(file,"Setembro de %d\nSalario: %f\nTranslado: %f\nCompras: %f\nLuz: %f\nÁgua: %f\nAluguel: %f\nFaculdade: %f\nSaldo: %f\n",year,a.salary,a.contas[0][mes],a.contas[1][mes],a.contas[2][mes],a.contas[3][mes],a.contas[4][mes],a.contas[5][mes],a.contas[6][mes]);
    fclose(file);
  }
  else if(mes == 9){
    file = fopen("extrato.txt", "a");
    fprintf(file,"Outubro de %d\nSalario: %f\nTranslado: %f\nCompras: %f\nLuz: %f\nÁgua: %f\nAluguel: %f\nFaculdade: %f\nSaldo: %f\n",year,a.salary,a.contas[0][mes],a.contas[1][mes],a.contas[2][mes],a.contas[3][mes],a.contas[4][mes],a.contas[5][mes],a.contas[6][mes]);
    fclose(file);
  }
  else if(mes == 10){
    file = fopen("extrato.txt", "a");
    fprintf(file,"Novembro de %d\nSalario: %f\nTranslado: %f\nCompras: %f\nLuz: %f\nÁgua: %f\nAluguel: %f\nFaculdade: %f\nSaldo: %f\n",year,a.salary,a.contas[0][mes],a.contas[1][mes],a.contas[2][mes],a.contas[3][mes],a.contas[4][mes],a.contas[5][mes],a.contas[6][mes]);
    fclose(file);
  }
  else if(mes == 11){
    file = fopen("extrato.txt", "a");
    fprintf(file,"Dezembro de %d\nSalario: %f\nTranslado: %f\nCompras: %f\nLuz: %f\nÁgua: %f\nAluguel: %f\nFaculdade: %f\nSaldo: %f\n",year,a.salary,a.contas[0][mes],a.contas[1][mes],a.contas[2][mes],a.contas[3][mes],a.contas[4][mes],a.contas[5][mes],a.contas[6][mes]);
    fclose(file);
  }
}
