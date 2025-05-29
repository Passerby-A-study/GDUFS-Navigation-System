#include"path_finding.h"

void floyd()
{
    // ��ʼ�����·������Ϊ�ڽӾ���ĸ���
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            shortest_path[i][j] = adjm[i][j];
            prev[i][j] = (i == j) ? -1 : i;  // ��ʼǰ��Ϊ��㱾��i��jֱ������ʱǰ��Ϊi��
        }
    }

    // ��������ѭ����������kΪ�м�ڵ����i��j�����·��
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // ������k��·�����̣���������·����ǰ��
                if (shortest_path[i][k] != INF && shortest_path[k][j] != INF &&
                    shortest_path[i][j] > shortest_path[i][k] + shortest_path[k][j]) {
                    shortest_path[i][j] = shortest_path[i][k] + shortest_path[k][j];
                    prev[i][j] = prev[k][j];  // ����ǰ��Ϊk��j��ǰ��
                }
            }
        }
    }
}
