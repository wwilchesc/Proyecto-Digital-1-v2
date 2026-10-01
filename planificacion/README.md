# Planificación del proyecto

Archivos de esta carpeta:

| Archivo | Contenido |
|---|---|
| [`equipos.md`](equipos.md) | Grupos A–L, integrantes y dependencias |
| [`cronograma.md`](cronograma.md) | Línea base del plan: tareas con responsable, fechas, dependencias, estado y evidencia |
| `README.md` (este) | Cómo configurar y usar GitHub Projects |

## Herramienta: GitHub Projects

Usamos **un solo GitHub Project** asociado a este repositorio general. Los *issues* pueden estar en este repositorio o en el de cada grupo, pero todos se agregan al mismo proyecto.

### Campos del proyecto

| Campo | Tipo |
|---|---|
| Estado | Selección: Pendiente, En desarrollo, Bloqueada, Terminada |
| Equipo | Selección: A, B, C, D, E, F, G, H, I, J, K, L |
| Responsable | Persona (*Assignees*) |
| Fecha de inicio | Fecha |
| Fecha de entrega | Fecha |
| Dependencias | Texto o enlace a otro *issue* |
| Repositorio | Repositorio |
| Evidencia / Pull request | Texto o enlace |
| Checkpoint | Selección: 1 CSR, 2 ASM, 3 RTL, 4 Hardware, 5 Demo |

### Vistas

1. **Seguimiento**: tabla agrupada por *Equipo* y ordenada por *Estado*.
2. **Cronograma**: *roadmap* con *Fecha de inicio* y *Fecha de entrega*.

### Pasos para crearlo (una sola vez, lo hace el Grupo A)

1. En GitHub: tu perfil → **Projects → New project → Table**. Nombre: `Consola FPGA — Digital 1`.
2. Agregar los campos de la tabla anterior con **+ New field**.
3. Crear la vista **Roadmap** (botón **+ New view → Roadmap**) y elegir las dos fechas.
4. En **Settings → Manage access**, invitar a los integrantes como *Write*.
5. Enlazar el proyecto a este repositorio y a los repositorios de cada grupo (**Projects → Link a project** en cada repo).

## Ciclo de una tarea

1. **Crear** el issue con el formulario **Tarea del proyecto Digital 1** ([`tarea.yml`](../.github/ISSUE_TEMPLATE/tarea.yml)). Usar el ID del cronograma en el título, por ejemplo `[Digital 1] T-E-03 RTL del teclado PS/2`.
2. **Asignar** a la persona responsable. Cada issue tiene un solo responsable.
3. **Agregar** el issue al Project y llenar fechas, dependencias, equipo y checkpoint.
4. **Trabajar** en una rama `feat/<periferico>-<tema>`. Los commits van a nombre de quien hizo el trabajo.
5. **Abrir el pull request** con `Closes #<issue>` en la descripción y pegar la evidencia: salida de `make sim`, captura de GTKWave o foto/video en la FPGA.
6. **Cerrar** la tarea solo cuando la evidencia sea verificable. Si está bloqueada, cambiar el estado a *Bloqueada* y enlazar el issue que la bloquea.
