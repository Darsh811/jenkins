pipeline {
  agent any
  stages {
       stage('Build') {
         steps {
             sh 'mvn clean install'
             echo 'Build Stage Sucessful'
             }
        }
         stage('Test') {
         steps {
            sh 'mvn test'
            echo 'Test Stage Sucessful'
            post {
              always {
                 junit 'target/surefire-reports/*.xml'
                 }
               } 
            } 
        }   
        stage('Deploy') {
          steps {
           sh 'mvn deploy'
           echo 'Deployment Sucessful'
           }
         }
       }
       post {
          failure {
               echo 'Pipeline failed'
               }
            }
        }    
