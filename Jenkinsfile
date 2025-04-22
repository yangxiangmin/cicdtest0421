pipeline {
    agent any
    environment {
        REPO_URL = "git@github.com:yangxiangmin/cicdtest0421.git"
        BUILD_DIR = "build"
        ARTIFACTS_DIR = "artifacts"
    }

    stages {
        // 1. 代码检出
        stage('Checkout') {
            steps {
                git url: env.REPO_URL, branch: 'main'
                sh 'echo "✅ 代码检出完成"'
            }
        }

        // 2. 编译
        stage('Build') {
            steps {
                sh """
                    mkdir -p ${env.BUILD_DIR}
                    cd ${env.BUILD_DIR}
                    cmake -DCMAKE_CXX_STANDARD=11 ..
                    make
                """
                sh 'echo "✅ 编译完成"'
            }
        }

        // 3. 单元测试（简单运算）
        stage('Unit Test') {
            steps {
                sh """
                    cd ${env.BUILD_DIR}
                    ./unit_tests --gtest_output="xml:unit-test-results.xml"
                """
                junit "${env.BUILD_DIR}/unit-test-results.xml"
                sh 'echo "✅ 单元测试通过"'
            }
        }

        // 4. 系统测试（混合运算）
        stage('System Test') {
            steps {
                sh """
                    cd ${env.BUILD_DIR}
                    ./system_tests --gtest_output="xml:system-test-results.xml"
                """
                junit "${env.BUILD_DIR}/system-test-results.xml"
                sh 'echo "✅ 系统测试通过"'
            }
        }

        // 5. 打包
        stage('Package') {
            steps {
                sh """
                    mkdir -p ${env.ARTIFACTS_DIR}
                    cp ${env.BUILD_DIR}/libmath_ops.a ${env.ARTIFACTS_DIR}/
                    tar -czvf math_ops-$(date +%Y%m%d).tar.gz ${env.ARTIFACTS_DIR}
                """
                archiveArtifacts artifacts: '*.tar.gz'
                sh 'echo "✅ 打包完成"'
            }
        }

        // 6. 部署（手动确认）
        stage('Deploy') {
            steps {
                script {
                    def confirm = input(
                        message: '确认部署到生产环境？',
                        parameters: [choice(name: 'action', choices: ['no', 'yes'])]
                    )
                    if (confirm == 'yes') {
                        sshPublisher(
                            publishers: [
                                sshPublisherDesc(
                                    configName: 'proenv',
                                    transfers: [
                                        sshTransfer(
                                            sourceFiles: '*.tar.gz',
                                            remoteDirectory: '/opt/math_ops',
                                            execCommand: 'cd /opt/math_ops && tar -xzvf *.tar.gz' && rm -f math_ops-*.tar.gz
                                        )
                                    ]
                                )
                            ]
                        )
                        sh 'echo "✅ 部署完成"'
                    }
                }
            }
        }
    }

    post {
        failure {
            emailext body: '构建失败: ${BUILD_URL}console',
                     subject: 'MathOps 构建失败',
                     to: 'team@example.com'
        }
    }
}