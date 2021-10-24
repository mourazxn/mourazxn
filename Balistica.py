import numpy as np 
from math import sqrt
import matplotlib.pyplot as pp


#Transforma de Km/h para m/s
transforma = input("Deseja transforma Km/h em m/(Sim ou Não): ").lower()
if(transforma == "sim"):
  trans = float(input("Digite a sua velocidade em Km/h: "))
  transformado = round(trans / 3.6)
  print("Velocidade transformada:", transformado,"m/s")

if(transforma == "não" or transforma == "nao"):
  velocidade = float(input("Digite a velocidade em m/s: "))
  print("Sua velocida e de",velocidade,"m/s")
#Digita todas as informações necessárias
while True:
  V0 = float(input("\nDigite a velocida em m/s: "))
  if(V0 <= 0):
    print("Valor inválido! Digite a velocidade positiva.")
  
  Angulo = float(input("Digite o ângulo de lançamento (em graus): "))
  if(Angulo < 0 or Angulo > 90):
    print("Valor inválido! Digite o ângulo entre 0 e 90 graus.")
  X0 = float(input("Digite o X0: "))
  Y0 = float(input("Digite o Y0: "))
  tempo = float(input("Digite um tempo: "))
  break
angRad = np.deg2rad(Angulo) #angulo
#g = float(input("Digite o valor da gravidade que quer usar: "))

g = 9.81 #gravidade sendo usada
#calculo que foram feitos
alcanceMax = round((V0**2) * np.sin(2*angRad) / g, 1)
alturaMax = round((V0**2) * (np.sin(angRad))**2 / (2*g), 1)
tempoTotal = round((((2*V0) * np.sin(angRad)) / g), 1)
#Calculo da velocidade V0x e V0y
Vx = V0 * np.cos(angRad)
Vy = (V0 * np.sin(angRad)-g * tempo)
#tg = Vx/Vy
#Velocidade quando alcançou a altura máxima
Vxx = Vx / 2
Vyy = Vy /2
#Quando atinge o solo
Vyy = round(V0 * np.sin(angRad)-g * tempoTotal)
#Modulo da velocida V0y em y
if(Vy < 0):
  Voy = Vy * -1
t = np.arange(0, tempoTotal, 0.1)
#Para fazer o gráfico
x = abs(V0) * np.cos(angRad) * t
y = (abs(V0) * np.sin(angRad) * t) - ((g*(t**2))/2)
#Posição de x e y no tempo que o usuario digitou
V0x = V0 * np.cos(angRad)
V0y = V0 * np.sin(angRad)
px = (X0 + Vx * tempo)
py = (Y0 + V0y * tempo - 1/2 * g * tempo**2)
#modulos
modulo = sqrt(Vx**2+Vy**2)
modulo2 = sqrt(V0x**2 + V0y**2)

print("\n\n\n*****************************************************|")
print("Componentes em x: V0x = V0 * cos(angulo)")
print("Componentes em y: V0y = V0 * sin(angulo)")
print(f"Componente em x: {V0x:.2f} m/s")
print(f"Componente em y: {V0y:.2f} m/s")
print(f"Módulo das componentes V0x e V0y: {modulo2:.2f} m/s")
print(f"Distância percorrida: {alcanceMax:.2f} metros")
print(f"Altura máxima: {alturaMax:.2f} metros")
print(f"Velocidade em X quando atinge a altura máxima: {Vx:.2f} m/s")
print(f"Velocidade em Y quando atinge a altura máxima: {Vy:.2f} m/s")
print(f"Módulo da velocidade: {modulo:.2f} m/s")
print(f"Quando atinge o solo: {Vyy:.2f} m")
print(f"Duração do lançamento: {tempoTotal:.2f} segundos")
print(f"Posição de x no tempo digitado: {px:.2f} m")
print(f"Posição de y no tempo digitado: {py:.2f} m")
print(f"Velocidade em Vx: {Vx:.2f} m/s")
print(f"Velocidade em Vy: {Vy:.2f} m/s")
print("***********************************************************|")

pp.title("Trajetória do Projétil")
pp.xlabel("Distância (m)")
pp.ylabel("Altura (m)")

pp.plot(x, y, 'r3')
pp.show()
