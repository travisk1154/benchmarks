# Data Table
Compiled with nvcc (no optimization flags)

| Count    | Size  | `Memcpy`     | `Pack_unpack`| `Pack_Unpack_GPU` | `Pack_Unpack_NC` |
|----------|-------|--------------|--------------|-----------------|----------------|
| 0        |       | 0.0000008780 | 0.0000002500 | 0.0000001800    | 0.0000002000   |
| 1        |       | 0.0000006340 | 0.0000021600 | 0.0025827700    | 0.0000009100   |
| 2        |       | 0.0000002470 | 0.0000017500 | 0.0000207800    | 0.0000006500   |
| 4        |       | 0.0000002450 | 0.0000016600 | 0.0000208700    | 0.0000006600   |
| 8        |       | 0.0000002480 | 0.0000017100 | 0.0000207800    | 0.0000006600   |
| 16       |       | 0.0000002500 | 0.0000017600 | 0.0000206900    | 0.0000006400   |
| 32       |       | 0.0000002600 | 0.0000018000 | 0.0000209600    | 0.0000006200   |
| 64       |       | 0.0000002760 | 0.0000018200 | 0.0000208600    | 0.0000006700   |
| 128      |       | 0.0000002880 | 0.0000017900 | 0.0000210000    | 0.0000007300   |
| 256      |       | 0.0000002770 | 0.0000017600 | 0.0000210700    | 0.0000007700   |
| 512      |       | 0.0000002950 | 0.0000018700 | 0.0000210800    | 0.0000009700   |
| 1024     | 1KB   | 0.0000003680 | 0.0000021200 | 0.0000211200    | 0.0000013200   |
| 2048     | 2KB   | 0.0000006390 | 0.0000024400 | 0.0000211900    | 0.0000021400   |
| 4096     | 4KB   | 0.0000013570 | 0.0000040300 | 0.0000211100    | 0.0000038700   |
| 8192     | 8KB   | 0.0000024340 | 0.0000061400 | 0.0000212700    | 0.0000073900   |
| 16384    | 16KB  | 0.0000045530 | 0.0000106500 | 0.0000213500    | 0.0000157200   |
| 32768    | 32KB  | 0.0000099590 | 0.0000242800 | 0.0000217000    | 0.0000302900   |
| 65536    | 64KB  | 0.0000192070 | 0.0000438800 | 0.0000229100    | 0.0000595800   |
| 131072   | 128KB | 0.0000353190 | 0.0000672200 | 0.0000251200    | 0.0001184700   |
| 262144   | 256KB | 0.0000697340 | 0.0000982700 | 0.0000270400    | 0.0002448800   |
| 524288   | 512KB | 0.0001478800 | 0.0001414600 | 0.0000439500    | 0.0007187200   |
| 1048576  | 1MB   | 0.0003224600 | 0.0002494600 | 0.0000770900    | 0.0018998300   |
| 2097152  | 2MB   | 0.0014336400 | 0.0006415200 | 0.0001286900    | 0.0044358600   |
| 4194304  | 4MB   | 0.0024988000 | 0.0019249900 | 0.0002323000    | 0.0094897400   |
| 8388608  | 8Mb   | 0.0056355100 | 0.0039775700 | 0.0004396000    | 0.0192205400   |
| 16777216 | 16MB  | 0.0115984500 | 0.0076660000 | 0.0008584000    | 0.0389174600   |
| 33554432 | 32MB  | 0.0232841600 | 0.0149343400 | 0.0017310300    | 0.0772243000   |