<p align="center">
  <a href="README.md">🇪🇸 Español</a> • <a href="README.en.md">🇺🇸 English</a>
</p>

---
# ft_minitalk 🧠💬

**ft_minitalk** es un sistema de comunicación en UNIX basado en señales entre dos procesos independientes — un cliente y un servidor — desarrollado como parte del currículo de 42.  
El reto: usar **únicamente** `SIGUSR1` y `SIGUSR2` para transmitir datos, obligando a crear un protocolo de comunicación propio desde cero.

---

## 📦 Descripción del Proyecto

El proyecto consta de dos programas:

- **`server`** – Espera mensajes y los muestra en tiempo real.  
- **`client`** – Envía un mensaje definido por el usuario al servidor utilizando solo señales.

Toda la comunicación se basa exclusivamente en `SIGUSR1` y `SIGUSR2`, lo que requiere codificación, transmisión y decodificación a nivel de bits.

---

## 📚 Contexto Teórico

**¿Qué son las señales?**  
En UNIX, las señales son interrupciones de software enviadas de un proceso a otro.  
Cada señal tiene un código único y puede invocar un *signal handler* personalizado.

Para este proyecto:
- `SIGUSR1` → representa **bit 1**
- `SIGUSR2` → representa **bit 0**

💡 **Naturaleza asíncrona:** Cuando se recibe una señal, interrumpe la ejecución normal del programa y llama inmediatamente al manejador registrado, sin importar qué estuviera haciendo el programa.

**Manejo de señales:**  
Usando `sigaction()` en el servidor, cada señal es capturada y procesada **bit a bit**.  
Cuando se han reunido 8 bits, se convierten de nuevo en un carácter y se imprimen.

---

## 💡 Cómo Funciona

### **Servidor**
1. Se inicia **sin argumentos**.
2. Muestra su PID (Process ID) al arrancar.
3. Espera señales entrantes del cliente.
4. Recoge bits, reconstruye caracteres y los imprime.
5. Envía una señal de confirmación (`SIGUSR1`) al cliente después de cada carácter.

### **Cliente**
1. Se lanza con:
   - El PID del servidor.
   - El mensaje a enviar.
2. Convierte cada carácter en **binario de 8 bits**.
3. Envía cada bit al servidor:
   - `SIGUSR1` para 1
   - `SIGUSR2` para 0
4. Espera confirmación del servidor antes de enviar el siguiente carácter.
5. Finaliza enviando una señal **EOT (End Of Transmission)**.

---

## 🧠 Lógica del Proyecto

En lugar de usar operaciones de bits tradicionales (máscaras y desplazamientos), este proyecto emplea un **sistema basado en buffer** para recopilar los bits recibidos.  
Fue una decisión intencionada, ya que en ese momento las operaciones bit a bit eran algo nuevo para mí.

**Flujo de transferencia del mensaje:**
1. Convertir caracteres → binario (8 bits cada uno).
2. Enviar bits vía `SIGUSR1`/`SIGUSR2`.
3. El servidor acumula bits y reconstruye los caracteres.
4. El servidor envía confirmación → el cliente envía el siguiente carácter.
5. Repetir hasta completar el mensaje → enviar EOT.

**Control de tiempos:**  
Para evitar pérdida de datos, el cliente usa `usleep(50)` entre bits.  
Las confirmaciones del servidor reducen retrasos innecesarios.

---

## 🔍 Validación de Entrada

- **Servidor**: No recibe argumentos.  
- **Cliente**: Requiere exactamente **dos argumentos**:
  1. PID del servidor.
  2. Mensaje a enviar.

**Validación de PID:**
- Debe ser numérico.
- Debe estar dentro del rango esperado de PIDs.
- Formatos inválidos generan un error.

---

## ⚡ Fiabilidad y Rendimiento

Este método basado en buffer, aunque más difícil de implementar, demostró ser **más fiable y robusto** que muchas implementaciones comunes.  
Versiones típicas — que dependen de temporizaciones menos estrictas o que no usan protocolos de confirmación — suelen fallar o perder datos con mensajes grandes (por ejemplo, de **1.000** o incluso **10.000 caracteres**).

Al imponer confirmaciones **bit a bit** y usar un sistema de buffer personalizado, esta implementación mantiene la estabilidad incluso con cargas elevadas, garantizando que **no se pierda ningún carácter** sin importar el tamaño del mensaje.

---

## ✨ Destacados y Reflexiones

- Protocolo binario personalizado usando solo dos señales.  
- Manejo robusto de señales con `sigaction()`.  
- Sistema de confirmación síncrono para asegurar la entrega.  
- Método alternativo al bitwise clásico usando buffer dinámico.  
- Retraso mínimo con `usleep(50)` por bit.  
- Estable incluso con transmisiones de más de 10k caracteres.

---

## 🚀 Compilación y Ejecución

**Compilar**
```bash
make
````

**Ejecutar Servidor**

```bash
./server
```

*Salida:*

```
PID: 12345
```

**Ejecutar Cliente**

```bash
./client 12345 "Hola desde el cliente!"
```

**Salida en Servidor:**

```
Hola desde el cliente!
```

---

## 🛠️ Funcionalidades Extra

* Protocolo personalizado basado en confirmaciones.
* Manejo fiable de señales con `sigaction()`.
* Buffer dinámico sin operaciones bitwise complejas.
* Validación de entrada básica pero efectiva.
* Estabilidad garantizada con mensajes muy largos.
