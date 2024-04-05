/*
 * File: main.c
 * Author: Federico Rinaldi - info@federicorinaldi.com
 * Description: NodeModulesFinder - An application to search and delete "node_modules" folders recursively.
 * Compilation: gcc main.c node_modules_finder.c -o node_modules_finder -o NodeModulesFinder
 * Usage: ./NodeModulesFinder
 * 
 * This program is licensed under the Apache License, Version 2.0.
 * You may obtain a copy of the License at
 * 
 *    http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "node_modules_finder.h"
#include <stdio.h>
#include <string.h>

int main() {

    printf("\033[1;35m"); // text color Magenta
    printf("  _   _           _      __  __           _       _      ______ _           _            \n");
    printf(" | \\ | |         | |    |  \\/  |         | |     | |    |  ____(_)         | |           \n");
    printf(" |  \\| | ___   __| | ___| \\  / | ___   __| |_   _| | ___| |__   _ _ __   __| | ___ _ __  \n");
    printf(" | . ` |/ _ \\ / _` |/ _ \\ |\\/| |/ _ \\ / _` | | | | |/ _ \\  __| | | '_ \\ / _` |/ _ \\ '__| \n");
    printf(" | |\\  | (_) | (_| |  __/ |  | | (_) | (_| | |_| | |  __/ |    | | | | | (_| |  __/ |    \n");
    printf(" |_| \\_|\\___/ \\__,_|\\___|_|  |_|\\___/ \\__,_|\\__,_|_|\\___|_|    |_|_| |_|\\__,_|\\___|_|    \n");
    printf("\033[0m"); // Reset Color

    printf("\n");
    printf("***********************************************************\n");
    printf("*     Welcome to NodeModulesFinder application            *\n");
    printf("*            Manage your node_modules folders             *\n");
    printf("***********************************************************\n");

    char rootPath[1024];

    // Ask the user for the path of the folder to start the search from.
    printf("Enter the path of the folder from which you want to start the search: ");
    fgets(rootPath, sizeof(rootPath), stdin);

    // Remove the newline character from the end of the string.
    rootPath[strcspn(rootPath, "\n")] = 0;

    findNodeModulesFolders(rootPath);

    char risposta[5];
    printf("Do you want to delete these 'node_modules' folders? (s/n): ");
    scanf("%s", risposta);

    if (strcmp(risposta, "s") == 0 || strcmp(risposta, "S") == 0) {
        deleteNodeModulesFolders(rootPath);
        printf("The 'node_modules' folders have been deleted.\n");
    }else {
        printf("No 'node_modules' folders were deleted.\n");
    }

    return 0;
}
